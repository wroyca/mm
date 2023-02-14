
#ifndef _GTKMM_EXPRESSION_H
#define _GTKMM_EXPRESSION_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/expressionwatch.hxx>

namespace Gtk
{

  class GTKMM_API ExpressionBase
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = ExpressionBase;
    using BaseObjectType = GtkExpression;
#endif

    void
    reference () const;

    void
    unreference () const;

    auto
    gobj () -> GtkExpression*;

    auto
    gobj () const -> const GtkExpression*;

    auto
    gobj_copy () const -> GtkExpression*;

    ExpressionBase () = delete;

    ExpressionBase (const ExpressionBase&) = delete;
    auto
    operator= (const ExpressionBase&) -> ExpressionBase& = delete;

  protected:
    void
    operator delete (void*, std::size_t);

  private:
  public:
    using SlotNotify = sigc::slot<void ()>;

    auto
    get_value_type () const -> GType;

    auto
    is_static () const -> bool;
  };

  template <class T>
  class Expression : public ExpressionBase
  {
  public:
    using ValueType = T;

    auto
    evaluate (const Glib::RefPtr<Glib::ObjectBase>& this_) -> std::optional<T>;

    auto
    watch (const Glib::RefPtr<Glib::ObjectBase>& this_,
           const SlotNotify& notify) -> Glib::RefPtr<ExpressionWatch<T>>;

    template <class T2>
    auto
    bind (const Glib::PropertyProxy<T2>& property,
          const Glib::RefPtr<Glib::ObjectBase>& this_ = nullptr)
        -> Glib::RefPtr<ExpressionWatch<T>>;

    template <class T2>
    auto
    bind (const Glib::PropertyProxy_WriteOnly<T2>& property,
          const Glib::RefPtr<Glib::ObjectBase>& this_ = nullptr)
        -> Glib::RefPtr<ExpressionWatch<T>>;
  };

  template <class T>
  class PropertyExpression final : public Expression<T>
  {
  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

    static auto
    create (GType this_type, const Glib::ustring& property_name)
        -> Glib::RefPtr<PropertyExpression>;

    template <class OT>
    static auto
    create (const Glib::RefPtr<OT>& expression,
            const Glib::ustring& property_name)
        -> Glib::RefPtr<PropertyExpression>;

    template <class OT>
    static auto
    create (GType this_type,
            const Glib::RefPtr<OT>& expression,
            const Glib::ustring& property_name)
        -> Glib::RefPtr<PropertyExpression>;
  };

  template <class T>
  class ConstantExpression final : public Expression<T>
  {
  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

    template <class... T_Args>
    static auto
    create (T_Args&&... args) -> Glib::RefPtr<ConstantExpression<T>>;

    static auto
    create_for_value (const Glib::Value<T>& value)
        -> Glib::RefPtr<ConstantExpression<T>>;
  };

  template <class T>
  class ObjectExpression final : public Expression<T>
  {
  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

    static auto
    create (const T& object) -> Glib::RefPtr<ObjectExpression<T>>;
  };

  template <class T>
  class ClosureExpression final : public Expression<T>
  {
  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

    template <class S, class... ATs>
    static auto
    create (S slot, const Glib::RefPtr<ATs>&... params)
        -> Glib::RefPtr<ClosureExpression<T>>;

  private:
    template <class A1, class... ATs>
    static void
    fill_params (GtkExpression** gparams,
                 const Glib::RefPtr<A1>& a1,
                 const Glib::RefPtr<ATs>&... eas);

    static void
    fill_params (GtkExpression** gparams);
  };

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  namespace Expression_Private
  {

    GTKMM_API
    void
    watch_callback (gpointer data);

    template <class T, class... ATs>
    class Invoker
    {
    public:
      explicit Invoker (const sigc::slot<T (ATs...)>& slot);
      void
      invoke (const GValue* param_values, GValue* return_value);

    private:
      sigc::slot<T (ATs...)> the_slot;

      template <class PT>
      auto
      eval_param (const GValue* gv) -> PT;

      template <std::size_t... I>
      void
      invoke (const GValue* param_values,
              GValue* return_value,
              std::index_sequence<I...>);
    };

    template <class TI>
    void
    closure_marshal (GClosure* closure,
                     GValue* return_value,
                     guint n_param_values,
                     const GValue* param_values,
                     gpointer invocation_hint,
                     gpointer marshal_data);

    GTKMM_API
    void
    closure_callback_func ();

    template <class TI>
    void
    closure_destroy (gpointer data, GClosure* closure);

  } // namespace Expression_Private

  template <class T>
  auto
  Expression<T>::evaluate (const Glib::RefPtr<Glib::ObjectBase>& this_) -> std::optional<T>
  {
    Glib::Value<T> value;
    bool result = gtk_expression_evaluate (gobj (),
                                           this_ ? this_->gobj () : nullptr,
                                           value.gobj ());
    if (!result)
      return {};

    if (!G_VALUE_HOLDS (value.gobj (), Glib::Value<T>::value_type ()))
    {
      g_warning ("%s: The evaluated expression has type '%s', expected '%s'",
                 G_STRLOC,
                 g_type_name (G_VALUE_TYPE (value.gobj ())),
                 g_type_name (Glib::Value<T>::value_type ()));
      return {};
    }

    return value.get ();
  }

  template <class T>
  auto
  Expression<T>::watch (const Glib::RefPtr<Glib::ObjectBase>& this_,
                        const SlotNotify& notify) -> Glib::RefPtr<ExpressionWatch<T>>
  {
    auto slot_copy = new SlotNotify (notify);
    return Glib::wrap<T> (
        gtk_expression_watch (gobj (),
                              this_ ? this_->gobj () : nullptr,
                              &Expression_Private::watch_callback,
                              slot_copy,
                              &Glib::destroy_notify_delete<SlotNotify>),
        true);
  }

  template <class T>
  template <class T2>
  auto
  Expression<T>::bind (const Glib::PropertyProxy<T2>& property,
                       const Glib::RefPtr<Glib::ObjectBase>& this_) -> Glib::RefPtr<ExpressionWatch<T>>
  {
    return Glib::wrap<T> (
        gtk_expression_bind (gobj_copy (),
                             property.get_object ()->gobj (),
                             property.get_name (),
                             this_ ? this_->gobj () : nullptr),
        true);
  }

  template <class T>
  template <class T2>
  auto
  Expression<T>::bind (const Glib::PropertyProxy_WriteOnly<T2>& property,
                       const Glib::RefPtr<Glib::ObjectBase>& this_) -> Glib::RefPtr<ExpressionWatch<T>>
  {
    return Glib::wrap<T> (
        gtk_expression_bind (gobj_copy (),
                             property.get_object ()->gobj (),
                             property.get_name (),
                             this_ ? this_->gobj () : nullptr),
        true);
  }

  template <class T>
  auto
  PropertyExpression<T>::get_type () -> GType
  {
    return gtk_property_expression_get_type ();
  }

  template <class T>
  auto
  PropertyExpression<T>::create (GType this_type,
                                 const Glib::ustring& property_name) -> Glib::RefPtr<PropertyExpression<T>>
  {
    return Glib::make_refptr_for_instance<Gtk::PropertyExpression<T>> (
        reinterpret_cast<Gtk::PropertyExpression<T>*> (
            gtk_property_expression_new (this_type,
                                         nullptr,
                                         property_name.c_str ())));
  }

  template <class T>
  template <class OT>
  auto
  PropertyExpression<T>::create (const Glib::RefPtr<OT>& expression,
                                 const Glib::ustring& property_name) -> Glib::RefPtr<PropertyExpression<T>>
  {
    return Glib::make_refptr_for_instance<Gtk::PropertyExpression<T>> (
        reinterpret_cast<Gtk::PropertyExpression<T>*> (
            gtk_property_expression_new (
                Glib::Value<typename OT::ValueType>::value_type (),
                expression->gobj_copy (),
                property_name.c_str ())));
  }

  template <class T>
  template <class OT>
  auto
  PropertyExpression<T>::create (GType this_type,
                                 const Glib::RefPtr<OT>& expression,
                                 const Glib::ustring& property_name) -> Glib::RefPtr<PropertyExpression<T>>
  {
    return Glib::make_refptr_for_instance<Gtk::PropertyExpression<T>> (
        reinterpret_cast<Gtk::PropertyExpression<T>*> (
            gtk_property_expression_new (this_type,
                                         expression->gobj_copy (),
                                         property_name.c_str ())));
  }

  template <class T>
  auto
  ConstantExpression<T>::get_type () -> GType
  {
    return gtk_constant_expression_get_type ();
  }

  template <class T>
  template <class... T_Args>
  auto
  ConstantExpression<T>::create (T_Args&&... args) -> Glib::RefPtr<ConstantExpression<T>>
  {
    Glib::Value<T> value;
    value.init (Glib::Value<T>::value_type ());
    value.set (T (std::forward<T_Args> (args)...));
    return create_for_value (value);
  }

  template <class T>
  auto
  ConstantExpression<T>::create_for_value (const Glib::Value<T>& value) -> Glib::RefPtr<ConstantExpression<T>>
  {
    return Glib::make_refptr_for_instance<Gtk::ConstantExpression<T>> (
        reinterpret_cast<Gtk::ConstantExpression<T>*> (
            gtk_constant_expression_new_for_value (value.gobj ())));
  }

  template <class T>
  auto
  ObjectExpression<T>::get_type () -> GType
  {
    return gtk_object_expression_get_type ();
  }

  template <class T>
  auto
  ObjectExpression<T>::create (const T& object) -> Glib::RefPtr<ObjectExpression<T>>
  {
    return Glib::make_refptr_for_instance<Gtk::ObjectExpression<T>> (
        reinterpret_cast<Gtk::ObjectExpression<T>*> (
            gtk_object_expression_new (G_OBJECT (object->gobj ()))));
  }

  template <class T>
  auto
  ClosureExpression<T>::get_type () -> GType
  {
    return gtk_cclosure_expression_get_type ();
  }

  template <class T>
  template <class S, class... ATs>
  auto
  ClosureExpression<T>::create (S slot, const Glib::RefPtr<ATs>&... params) -> Glib::RefPtr<ClosureExpression<T>>
  {
    using TI = Expression_Private::
        Invoker<T, Glib::RefPtr<Glib::ObjectBase>, typename ATs::ValueType...>;
    auto invoker = new TI (slot);
    guint n_params = sizeof...(params);
    auto gparams = new GtkExpression*[n_params];
    fill_params (gparams, params...);

    auto object = gtk_cclosure_expression_new (
        Glib::Value<T>::value_type (),
        Expression_Private::closure_marshal<TI>,
        n_params,
        gparams,
        Expression_Private::closure_callback_func,
        invoker,
        Expression_Private::closure_destroy<TI>);
    delete[] gparams;

    return Glib::make_refptr_for_instance<Gtk::ClosureExpression<T>> (
        reinterpret_cast<Gtk::ClosureExpression<T>*> (object));
  }

  template <class T>
  template <class A1, class... ATs>
  void
  ClosureExpression<T>::fill_params (GtkExpression** gparams,
                                     const Glib::RefPtr<A1>& a1,
                                     const Glib::RefPtr<ATs>&... eas)
  {
    gparams[0] = a1->gobj_copy ();
    fill_params (gparams + 1, eas...);
  }

  template <class T>
  void
  ClosureExpression<T>::fill_params (GtkExpression**)
  {
  }

  namespace Expression_Private
  {

    template <class T, class... ATs>
    Invoker<T, ATs...>::Invoker (const sigc::slot<T (ATs...)>& slot)
      : the_slot (slot)
    {
    }

    template <class T, class... ATs>
    template <class PT>
    auto
    Invoker<T, ATs...>::eval_param (const GValue* gv) -> PT
    {
      Glib::Value<PT> v;
      v.init (gv);
      return v.get ();
    }

    template <class T, class... ATs>
    template <std::size_t... I>
    void
    Invoker<T, ATs...>::invoke (const GValue* param_values,
                                GValue* return_value,
                                std::index_sequence<I...>)
    {
      T res = the_slot (eval_param<ATs> (&param_values[I])...);
      Glib::Value<T> rv;
      rv.init (Glib::Value<T>::value_type ());
      rv.set (res);
      g_value_copy (rv.gobj (), return_value);
    }

    template <class T, class... ATs>
    void
    Invoker<T, ATs...>::invoke (const GValue* param_values,
                                GValue* return_value)
    {
      invoke (param_values,
              return_value,
              std::make_index_sequence<sizeof...(ATs)> ());
    }

    template <class TI>
    void
    closure_marshal (GClosure* closure,
                     GValue* return_value,
                     guint,
                     const GValue* param_values,
                     gpointer,
                     gpointer)
    {
      static_cast<TI*> (closure->data)->invoke (param_values, return_value);
    }

    template <class TI>
    void
    closure_destroy (gpointer, GClosure* closure)
    {
      delete static_cast<TI*> (closure->data);
    }

  } // namespace Expression_Private

#endif

} // namespace Gtk

namespace Glib
{

  template <class T>
  auto
  wrap (GtkExpression* object, bool take_copy = false) -> RefPtr<Gtk::Expression<T>>
  {
    if (take_copy && object)
      gtk_expression_ref (object);

    return Glib::make_refptr_for_instance<Gtk::Expression<T>> (
        reinterpret_cast<Gtk::Expression<T>*> (object));
  }

  template <class T>
  class Value<RefPtr<Gtk::Expression<T>>> : public ValueBase
  {
  public:
    using CppType = RefPtr<Gtk::Expression<T>>;

    static auto
    value_type () -> GType;

    void
    set (const CppType& data);
    auto
    get () const -> CppType;
  };

  template <class T>
  auto
  Value<RefPtr<Gtk::Expression<T>>>::value_type () -> GType
  {
    return gtk_expression_get_type ();
  }

  template <class T>
  void
  Value<RefPtr<Gtk::Expression<T>>>::set (const CppType& data)
  {
    gtk_value_set_expression (&gobject_,
                              const_cast<GtkExpression*> (data->gobj ()));
  }

  template <class T>
  auto
  Value<RefPtr<Gtk::Expression<T>>>::get () const ->
      typename Value<RefPtr<Gtk::Expression<T>>>::CppType
  {
    return wrap<T> (gtk_value_get_expression (&gobject_), true);
  }

} // namespace Glib

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkExpression* object, bool take_copy = false) -> Glib::RefPtr<Gtk::ExpressionBase>;

} // namespace Glib

#endif
