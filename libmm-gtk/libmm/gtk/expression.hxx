// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_EXPRESSION_H
#define _GTKMM_EXPRESSION_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/expressionwatch.hxx>

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT ExpressionBase
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = ExpressionBase;
    using BaseObjectType = GtkExpression;
#endif

    auto
    reference () const -> void;

    auto
    unreference () const -> void;

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
    auto
    operator delete (void*, std::size_t) -> void;

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
    evaluate (const glib::RefPtr<glib::ObjectBase>& this_) -> std::optional<T>;

    auto
    watch (const glib::RefPtr<glib::ObjectBase>& this_,
           const SlotNotify& notify) -> glib::RefPtr<ExpressionWatch<T>>;

    template <class T2>
    auto
    bind (const glib::PropertyProxy<T2>& property,
          const glib::RefPtr<glib::ObjectBase>& this_ = nullptr)
        -> glib::RefPtr<ExpressionWatch<T>>;

    template <class T2>
    auto
    bind (const glib::PropertyProxy_WriteOnly<T2>& property,
          const glib::RefPtr<glib::ObjectBase>& this_ = nullptr)
        -> glib::RefPtr<ExpressionWatch<T>>;
  };

  template <class T>
  class PropertyExpression final : public Expression<T>
  {
  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

    static auto
    create (GType this_type, const glib::ustring& property_name)
        -> glib::RefPtr<PropertyExpression>;

    template <class OT>
    static auto
    create (const glib::RefPtr<OT>& expression,
            const glib::ustring& property_name)
        -> glib::RefPtr<PropertyExpression>;

    template <class OT>
    static auto
    create (GType this_type,
            const glib::RefPtr<OT>& expression,
            const glib::ustring& property_name)
        -> glib::RefPtr<PropertyExpression>;
  };

  template <class T>
  class ConstantExpression final : public Expression<T>
  {
  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

    template <class... T_Args>
    static auto
    create (T_Args&&... args) -> glib::RefPtr<ConstantExpression<T>>;

    static auto
    create_for_value (const glib::Value<T>& value)
        -> glib::RefPtr<ConstantExpression<T>>;
  };

  template <class T>
  class ObjectExpression final : public Expression<T>
  {
  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

    static auto
    create (const T& object) -> glib::RefPtr<ObjectExpression<T>>;
  };

  template <class T>
  class ClosureExpression final : public Expression<T>
  {
  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

    template <class S, class... ATs>
    static auto
    create (S slot, const glib::RefPtr<ATs>&... params)
        -> glib::RefPtr<ClosureExpression<T>>;

  private:
    template <class A1, class... ATs>
    static auto
    fill_params (GtkExpression** gparams,
                 const glib::RefPtr<A1>& a1,
                 const glib::RefPtr<ATs>&... eas) -> void;

    static auto
    fill_params (GtkExpression** gparams) -> void;
  };

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  namespace Expression_Private
  {
    LIBMM_GTK_SYMEXPORT auto
    watch_callback (gpointer data) -> void;

    template <class T, class... ATs>
    class Invoker
    {
    public:
      explicit Invoker (const sigc::slot<T (ATs...)>& slot);
      auto
      invoke (const GValue* param_values, GValue* return_value) -> void;

    private:
      sigc::slot<T (ATs...)> the_slot;

      template <class PT>
      auto
      eval_param (const GValue* gv) -> PT;

      template <std::size_t... I>
      auto
      invoke (const GValue* param_values,
              GValue* return_value,
              std::index_sequence<I...>) -> void;
    };

    template <class TI>
    auto
    closure_marshal (GClosure* closure,
                     GValue* return_value,
                     guint n_param_values,
                     const GValue* param_values,
                     gpointer invocation_hint,
                     gpointer marshal_data) -> void;

    LIBMM_GTK_SYMEXPORT auto
    closure_callback_func () -> void;

    template <class TI>
    auto
    closure_destroy (gpointer data, GClosure* closure) -> void;

  } // namespace Expression_Private

  template <class T>
  auto
  Expression<T>::evaluate (const glib::RefPtr<glib::ObjectBase>& this_) -> std::optional<T>
  {
    glib::Value<T> value;
    bool result = gtk_expression_evaluate (gobj (),
                                           this_ ? this_->gobj () : nullptr,
                                           value.gobj ());
    if (!result)
      return {};

    if (!G_VALUE_HOLDS (value.gobj (), glib::Value<T>::value_type ()))
    {
      g_warning ("%s: The evaluated expression has type '%s', expected '%s'",
                 G_STRLOC,
                 g_type_name (G_VALUE_TYPE (value.gobj ())),
                 g_type_name (glib::Value<T>::value_type ()));
      return {};
    }

    return value.get ();
  }

  template <class T>
  auto
  Expression<T>::watch (const glib::RefPtr<glib::ObjectBase>& this_,
                        const SlotNotify& notify) -> glib::RefPtr<ExpressionWatch<T>>
  {
    auto slot_copy = new SlotNotify (notify);
    return glib::wrap<T> (
        gtk_expression_watch (gobj (),
                              this_ ? this_->gobj () : nullptr,
                              &Expression_Private::watch_callback,
                              slot_copy,
                              &glib::destroy_notify_delete<SlotNotify>),
        true);
  }

  template <class T>
  template <class T2>
  auto
  Expression<T>::bind (const glib::PropertyProxy<T2>& property,
                       const glib::RefPtr<glib::ObjectBase>& this_) -> glib::RefPtr<ExpressionWatch<T>>
  {
    return glib::wrap<T> (
        gtk_expression_bind (gobj_copy (),
                             property.get_object ()->gobj (),
                             property.get_name (),
                             this_ ? this_->gobj () : nullptr),
        true);
  }

  template <class T>
  template <class T2>
  auto
  Expression<T>::bind (const glib::PropertyProxy_WriteOnly<T2>& property,
                       const glib::RefPtr<glib::ObjectBase>& this_) -> glib::RefPtr<ExpressionWatch<T>>
  {
    return glib::wrap<T> (
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
                                 const glib::ustring& property_name) -> glib::RefPtr<PropertyExpression<T>>
  {
    return glib::make_refptr_for_instance<gtk::PropertyExpression<T>> (
        reinterpret_cast<gtk::PropertyExpression<T>*> (
            gtk_property_expression_new (this_type,
                                         nullptr,
                                         property_name.c_str ())));
  }

  template <class T>
  template <class OT>
  auto
  PropertyExpression<T>::create (const glib::RefPtr<OT>& expression,
                                 const glib::ustring& property_name) -> glib::RefPtr<PropertyExpression<T>>
  {
    return glib::make_refptr_for_instance<gtk::PropertyExpression<T>> (
        reinterpret_cast<gtk::PropertyExpression<T>*> (
            gtk_property_expression_new (
                glib::Value<typename OT::ValueType>::value_type (),
                expression->gobj_copy (),
                property_name.c_str ())));
  }

  template <class T>
  template <class OT>
  auto
  PropertyExpression<T>::create (GType this_type,
                                 const glib::RefPtr<OT>& expression,
                                 const glib::ustring& property_name) -> glib::RefPtr<PropertyExpression<T>>
  {
    return glib::make_refptr_for_instance<gtk::PropertyExpression<T>> (
        reinterpret_cast<gtk::PropertyExpression<T>*> (
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
  ConstantExpression<T>::create (T_Args&&... args) -> glib::RefPtr<ConstantExpression<T>>
  {
    glib::Value<T> value;
    value.init (glib::Value<T>::value_type ());
    value.set (T (std::forward<T_Args> (args)...));
    return create_for_value (value);
  }

  template <class T>
  auto
  ConstantExpression<T>::create_for_value (const glib::Value<T>& value) -> glib::RefPtr<ConstantExpression<T>>
  {
    return glib::make_refptr_for_instance<gtk::ConstantExpression<T>> (
        reinterpret_cast<gtk::ConstantExpression<T>*> (
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
  ObjectExpression<T>::create (const T& object) -> glib::RefPtr<ObjectExpression<T>>
  {
    return glib::make_refptr_for_instance<gtk::ObjectExpression<T>> (
        reinterpret_cast<gtk::ObjectExpression<T>*> (
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
  ClosureExpression<T>::create (S slot, const glib::RefPtr<ATs>&... params) -> glib::RefPtr<ClosureExpression<T>>
  {
    using TI = Expression_Private::
        Invoker<T, glib::RefPtr<glib::ObjectBase>, typename ATs::ValueType...>;
    auto invoker = new TI (slot);
    guint n_params = sizeof...(params);
    auto gparams = new GtkExpression*[n_params];
    fill_params (gparams, params...);

    auto object = gtk_cclosure_expression_new (
        glib::Value<T>::value_type (),
        Expression_Private::closure_marshal<TI>,
        n_params,
        gparams,
        Expression_Private::closure_callback_func,
        invoker,
        Expression_Private::closure_destroy<TI>);
    delete[] gparams;

    return glib::make_refptr_for_instance<gtk::ClosureExpression<T>> (
        reinterpret_cast<gtk::ClosureExpression<T>*> (object));
  }

  template <class T>
  template <class A1, class... ATs>
  auto
  ClosureExpression<T>::fill_params (GtkExpression** gparams,
                                     const glib::RefPtr<A1>& a1,
                                     const glib::RefPtr<ATs>&... eas) -> void
  {
    gparams[0] = a1->gobj_copy ();
    fill_params (gparams + 1, eas...);
  }

  template <class T>
  auto
  ClosureExpression<T>::fill_params (GtkExpression**) -> void
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
      glib::Value<PT> v;
      v.init (gv);
      return v.get ();
    }

    template <class T, class... ATs>
    template <std::size_t... I>
    auto
    Invoker<T, ATs...>::invoke (const GValue* param_values,
                                GValue* return_value,
                                std::index_sequence<I...>) -> void
    {
      T res = the_slot (eval_param<ATs> (&param_values[I])...);
      glib::Value<T> rv;
      rv.init (glib::Value<T>::value_type ());
      rv.set (res);
      g_value_copy (rv.gobj (), return_value);
    }

    template <class T, class... ATs>
    auto
    Invoker<T, ATs...>::invoke (const GValue* param_values,
                                GValue* return_value) -> void
    {
      invoke (param_values,
              return_value,
              std::make_index_sequence<sizeof...(ATs)> ());
    }

    template <class TI>
    auto
    closure_marshal (GClosure* closure,
                     GValue* return_value,
                     guint,
                     const GValue* param_values,
                     gpointer,
                     gpointer) -> void
    {
      static_cast<TI*> (closure->data)->invoke (param_values, return_value);
    }

    template <class TI>
    auto
    closure_destroy (gpointer, GClosure* closure) -> void
    {
      delete static_cast<TI*> (closure->data);
    }

  } // namespace Expression_Private

#endif

} // namespace gtk

namespace glib
{

  template <class T>
  auto
  wrap (GtkExpression* object, bool take_copy = false) -> RefPtr<gtk::Expression<T>>
  {
    if (take_copy && object)
      gtk_expression_ref (object);

    return glib::make_refptr_for_instance<gtk::Expression<T>> (
        reinterpret_cast<gtk::Expression<T>*> (object));
  }

  template <class T>
  class Value<RefPtr<gtk::Expression<T>>> : public ValueBase
  {
  public:
    using CppType = RefPtr<gtk::Expression<T>>;

    static auto
    value_type () -> GType;

    auto
    set (const CppType& data) -> void;
    auto
    get () const -> CppType;
  };

  template <class T>
  auto
  Value<RefPtr<gtk::Expression<T>>>::value_type () -> GType
  {
    return gtk_expression_get_type ();
  }

  template <class T>
  auto
  Value<RefPtr<gtk::Expression<T>>>::set (const CppType& data) -> void
  {
    gtk_value_set_expression (&gobject_,
                              const_cast<GtkExpression*> (data->gobj ()));
  }

  template <class T>
  auto
  Value<RefPtr<gtk::Expression<T>>>::get () const ->
      typename Value<RefPtr<gtk::Expression<T>>>::CppType
  {
    return wrap<T> (gtk_value_get_expression (&gobject_), true);
  }

} // namespace glib

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkExpression* object, bool take_copy = false) -> glib::RefPtr<gtk::ExpressionBase>;

} // namespace glib

#endif
