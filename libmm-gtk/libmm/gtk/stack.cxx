// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/stack.hxx>
#include <libmm/gtk/stack_p.hxx>

#include <gtk/gtk.h>

#include <gtk/gtk.h>
#include <libmm/gtk/selectionlistmodelimpl.hxx>

namespace gtk
{

  auto
  Stack::get_pages () -> glib::RefPtr<SelectionModel>
  {
    GtkSelectionModel* stack_pages = gtk_stack_get_pages (gobj ());
    if (G_IS_LIST_MODEL (stack_pages))
    {
      glib::ObjectBase* pCppObject =
          glib::ObjectBase::_get_current_wrapper ((GObject*) stack_pages);
      if (!pCppObject)
        pCppObject = new SelectionListModelImpl ((GObject*) stack_pages);
      return glib::make_refptr_for_instance<SelectionModel> (
          dynamic_cast<SelectionModel*> (pCppObject));
    }
    return glib::wrap (stack_pages);
  }

} // namespace gtk

namespace
{
}

namespace glib
{

  auto
  wrap (GtkStack* object, bool take_copy) -> gtk::Stack*
  {
    return dynamic_cast<gtk::Stack*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  Stack_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Stack_Class::class_init_function;

      register_derived_type (gtk_stack_get_type ());
    }

    return *this;
  }

  auto
  Stack_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  Stack_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new Stack ((GtkStack*) (o)));
  }

  Stack::Stack (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  Stack::Stack (GtkStack* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  Stack::Stack (Stack&& src) noexcept
    : gtk::Widget (std::move (src))
  {
  }

  auto
  Stack::operator= (Stack&& src) noexcept -> Stack&
  {
    gtk::Widget::operator= (std::move (src));
    return *this;
  }

  Stack::~Stack () noexcept
  {
    destroy_ ();
  }

  Stack::CppClassType Stack::stack_class_;

  auto
  Stack::get_type () -> GType
  {
    return stack_class_.init ().get_type ();
  }

  auto
  Stack::get_base_type () -> GType
  {
    return gtk_stack_get_type ();
  }

  Stack::Stack ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (stack_class_.init ()))
  {
  }

  auto
  Stack::add (Widget& child) -> glib::RefPtr<StackPage>
  {
    auto retvalue = glib::wrap (gtk_stack_add_child (gobj (), (child).gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Stack::add (Widget& child, const glib::ustring& name) -> glib::RefPtr<StackPage>
  {
    auto retvalue = glib::wrap (
        gtk_stack_add_named (gobj (), (child).gobj (), name.c_str ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Stack::add (Widget& child,
              const glib::ustring& name,
              const glib::ustring& title) -> glib::RefPtr<StackPage>
  {
    auto retvalue = glib::wrap (gtk_stack_add_titled (gobj (),
                                                      (child).gobj (),
                                                      name.c_str (),
                                                      title.c_str ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Stack::remove (Widget& child) -> void
  {
    gtk_stack_remove (gobj (), (child).gobj ());
  }

  auto
  Stack::get_page (Widget& child) -> glib::RefPtr<StackPage>
  {
    auto retvalue = glib::wrap (gtk_stack_get_page (gobj (), (child).gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Stack::get_page (const Widget& child) const -> glib::RefPtr<const StackPage>
  {
    auto retvalue = glib::wrap (
        gtk_stack_get_page (const_cast<GtkStack*> (gobj ()),
                            const_cast<GtkWidget*> ((child).gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Stack::set_visible_child (Widget& child) -> void
  {
    gtk_stack_set_visible_child (gobj (), (child).gobj ());
  }

  auto
  Stack::get_visible_child () -> Widget*
  {
    return glib::wrap (gtk_stack_get_visible_child (gobj ()));
  }

  auto
  Stack::get_visible_child () const -> const Widget*
  {
    return const_cast<Stack*> (this)->get_visible_child ();
  }

  auto
  Stack::set_visible_child (const glib::ustring& name) -> void
  {
    gtk_stack_set_visible_child_name (gobj (), name.c_str ());
  }

  auto
  Stack::set_visible_child (const glib::ustring& name,
                            StackTransitionType transition) -> void
  {
    gtk_stack_set_visible_child_full (
        gobj (),
        name.c_str (),
        static_cast<GtkStackTransitionType> (transition));
  }

  auto
  Stack::get_visible_child_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_stack_get_visible_child_name (const_cast<GtkStack*> (gobj ())));
  }

  auto
  Stack::set_hhomogeneous (bool hhomogeneous) -> void
  {
    gtk_stack_set_hhomogeneous (gobj (), static_cast<int> (hhomogeneous));
  }

  auto
  Stack::get_hhomogeneous () const -> bool
  {
    return gtk_stack_get_hhomogeneous (const_cast<GtkStack*> (gobj ()));
  }

  auto
  Stack::set_vhomogeneous (bool vhomogeneous) -> void
  {
    gtk_stack_set_vhomogeneous (gobj (), static_cast<int> (vhomogeneous));
  }

  auto
  Stack::get_vhomogeneous () const -> bool
  {
    return gtk_stack_get_vhomogeneous (const_cast<GtkStack*> (gobj ()));
  }

  auto
  Stack::set_transition_duration (guint duration) -> void
  {
    gtk_stack_set_transition_duration (gobj (), duration);
  }

  auto
  Stack::get_transition_duration () const -> guint
  {
    return gtk_stack_get_transition_duration (const_cast<GtkStack*> (gobj ()));
  }

  auto
  Stack::set_transition_type (StackTransitionType transition) -> void
  {
    gtk_stack_set_transition_type (
        gobj (),
        static_cast<GtkStackTransitionType> (transition));
  }

  auto
  Stack::get_transition_type () const -> StackTransitionType
  {
    return static_cast<StackTransitionType> (
        gtk_stack_get_transition_type (const_cast<GtkStack*> (gobj ())));
  }

  auto
  Stack::get_transition_running () const -> bool
  {
    return gtk_stack_get_transition_running (const_cast<GtkStack*> (gobj ()));
  }

  auto
  Stack::get_child_by_name (const glib::ustring& name) -> Widget*
  {
    return glib::wrap (gtk_stack_get_child_by_name (gobj (), name.c_str ()));
  }

  auto
  Stack::get_child_by_name (const glib::ustring& name) const -> const Widget*
  {
    return const_cast<Stack*> (this)->get_child_by_name (name);
  }

  auto
  Stack::set_interpolate_size (bool interpolate_size) -> void
  {
    gtk_stack_set_interpolate_size (gobj (),
                                    static_cast<int> (interpolate_size));
  }

  auto
  Stack::get_interpolate_size () const -> bool
  {
    return gtk_stack_get_interpolate_size (const_cast<GtkStack*> (gobj ()));
  }

  auto
  Stack::get_pages () const -> glib::RefPtr<const SelectionModel>
  {
    return const_cast<Stack*> (this)->get_pages ();
  }

  auto
  Stack::property_hhomogeneous () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "hhomogeneous");
  }

  auto
  Stack::property_hhomogeneous () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "hhomogeneous");
  }

  auto
  Stack::property_transition_duration () -> glib::PropertyProxy<unsigned int>
  {
    return glib::PropertyProxy<unsigned int> (this, "transition-duration");
  }

  auto
  Stack::property_transition_duration () const -> glib::PropertyProxy_ReadOnly<unsigned int>
  {
    return glib::PropertyProxy_ReadOnly<unsigned int> (this,
                                                       "transition-duration");
  }

  auto
  Stack::property_transition_running () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "transition-running");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<StackTransitionType>::value,
      "Type StackTransitionType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Stack::property_transition_type () -> glib::PropertyProxy<StackTransitionType>
  {
    return glib::PropertyProxy<StackTransitionType> (this, "transition-type");
  }

  auto
  Stack::property_transition_type () const -> glib::PropertyProxy_ReadOnly<StackTransitionType>
  {
    return glib::PropertyProxy_ReadOnly<StackTransitionType> (
        this,
        "transition-type");
  }

  auto
  Stack::property_vhomogeneous () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "vhomogeneous");
  }

  auto
  Stack::property_vhomogeneous () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "vhomogeneous");
  }

  auto
  Stack::property_visible_child () -> glib::PropertyProxy<Widget*>
  {
    return glib::PropertyProxy<Widget*> (this, "visible-child");
  }

  auto
  Stack::property_visible_child () const -> glib::PropertyProxy_ReadOnly<Widget*>
  {
    return glib::PropertyProxy_ReadOnly<Widget*> (this, "visible-child");
  }

  auto
  Stack::property_visible_child_name () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "visible-child-name");
  }

  auto
  Stack::property_visible_child_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this,
                                                        "visible-child-name");
  }

  auto
  Stack::property_interpolate_size () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "interpolate-size");
  }

  auto
  Stack::property_interpolate_size () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "interpolate-size");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<SelectionModel>>::value,
      "Type glib::RefPtr<SelectionModel> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Stack::property_pages () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<SelectionModel>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<SelectionModel>> (this,
                                                                       "pages");
  }

} // namespace gtk
