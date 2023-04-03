// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/viewstack.hxx>
#include <libmm/adw/viewstack_p.hxx>

#include <libmm/adw/selectionlistmodelimpl.hxx>
#include <libmm/gtk/mm-gtk.hxx>

namespace Adw
{

  auto
  ViewStack::get_pages () const -> Glib::RefPtr<Gtk::SelectionModel>
  {
    GtkSelectionModel* pages =
        adw_view_stack_get_pages (const_cast<AdwViewStack*> (gobj ()));
    g_assert (G_IS_LIST_MODEL (pages));

    Glib::ObjectBase* pCppObject =
        Glib::ObjectBase::_get_current_wrapper ((GObject*) pages);
    if (!pCppObject)
      pCppObject = new Adw::SelectionListModelImpl ((GObject*) pages);
    return Glib::make_refptr_for_instance<Gtk::SelectionModel> (
        dynamic_cast<Gtk::SelectionModel*> (pCppObject));
  }

} // namespace Adw

namespace
{
}

namespace Glib
{

  auto
  wrap (AdwViewStack* object, bool take_copy) -> Adw::ViewStack*
  {
    return dynamic_cast<Adw::ViewStack*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Adw
{

  auto
  ViewStack_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_view_stack_get_type ();
    }

    return *this;
  }

  auto
  ViewStack_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new ViewStack ((AdwViewStack*) (o)));
  }

  ViewStack::ViewStack (const Glib::ConstructParams& construct_params)
    : Gtk::Widget (construct_params)
  {
  }

  ViewStack::ViewStack (AdwViewStack* castitem)
    : Gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  ViewStack::ViewStack (ViewStack&& src) noexcept
    : Gtk::Widget (std::move (src))
  {
  }

  auto
  ViewStack::operator= (ViewStack&& src) noexcept -> ViewStack&
  {
    Gtk::Widget::operator= (std::move (src));
    return *this;
  }

  ViewStack::~ViewStack () noexcept
  {
    destroy_ ();
  }

  ViewStack::CppClassType ViewStack::viewstack_class_;

  auto
  ViewStack::get_type () -> GType
  {
    return viewstack_class_.init ().get_type ();
  }

  auto
  ViewStack::get_base_type () -> GType
  {
    return adw_view_stack_get_type ();
  }

  ViewStack::ViewStack ()
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (viewstack_class_.init ()))
  {
  }

  auto
  ViewStack::add (Gtk::Widget* child) -> Glib::RefPtr<ViewStackPage>
  {
    auto retvalue = Glib::wrap (
        adw_view_stack_add (gobj (), (GtkWidget*) Glib::unwrap (child)));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  ViewStack::add_named (Gtk::Widget* child, const Glib::ustring& name) -> Glib::RefPtr<ViewStackPage>
  {
    auto retvalue =
        Glib::wrap (adw_view_stack_add_named (gobj (),
                                              (GtkWidget*) Glib::unwrap (child),
                                              name.c_str ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  ViewStack::add_titled (Gtk::Widget* child,
                         const Glib::ustring& name,
                         const Glib::ustring& title) -> Glib::RefPtr<ViewStackPage>
  {
    auto retvalue = Glib::wrap (
        adw_view_stack_add_titled (gobj (),
                                   (GtkWidget*) Glib::unwrap (child),
                                   name.c_str (),
                                   title.c_str ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  ViewStack::add_titled_with_icon (Gtk::Widget* child,
                                   const Glib::ustring& name,
                                   const Glib::ustring& title,
                                   const Glib::ustring& icon_name) -> Glib::RefPtr<ViewStackPage>
  {
    auto retvalue = Glib::wrap (
        adw_view_stack_add_titled_with_icon (gobj (),
                                             (GtkWidget*) Glib::unwrap (child),
                                             name.c_str (),
                                             title.c_str (),
                                             icon_name.c_str ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  ViewStack::get_child_by_name (const Glib::ustring& name) const -> Gtk::Widget*
  {
    return Glib::wrap (
        adw_view_stack_get_child_by_name (const_cast<AdwViewStack*> (gobj ()),
                                          name.c_str ()));
  }

  auto
  ViewStack::get_hhomogeneous () const -> bool
  {
    return adw_view_stack_get_hhomogeneous (
        const_cast<AdwViewStack*> (gobj ()));
  }

  auto
  ViewStack::get_page (Gtk::Widget* child) const -> Glib::RefPtr<ViewStackPage>
  {
    auto retvalue = Glib::wrap (
        adw_view_stack_get_page (const_cast<AdwViewStack*> (gobj ()),
                                 (GtkWidget*) Glib::unwrap (child)));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  ViewStack::get_vhomogeneous () const -> bool
  {
    return adw_view_stack_get_vhomogeneous (
        const_cast<AdwViewStack*> (gobj ()));
  }

  auto
  ViewStack::get_visible_child () const -> Gtk::Widget*
  {
    return Glib::wrap (
        adw_view_stack_get_visible_child (const_cast<AdwViewStack*> (gobj ())));
  }

  auto
  ViewStack::get_visible_child_name () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        adw_view_stack_get_visible_child_name (
            const_cast<AdwViewStack*> (gobj ())));
  }

  auto
  ViewStack::remove (Gtk::Widget* widget) -> void
  {
    adw_view_stack_remove (gobj (), (GtkWidget*) Glib::unwrap (widget));
  }

  auto
  ViewStack::set_hhomogeneous (bool hhomogeneous) -> void
  {
    adw_view_stack_set_hhomogeneous (gobj (), static_cast<int> (hhomogeneous));
  }

  auto
  ViewStack::set_vhomogeneous (bool hhomogeneous) -> void
  {
    adw_view_stack_set_vhomogeneous (gobj (), static_cast<int> (hhomogeneous));
  }

  auto
  ViewStack::set_visible_child (Gtk::Widget* child) -> void
  {
    adw_view_stack_set_visible_child (gobj (),
                                      (GtkWidget*) Glib::unwrap (child));
  }

  auto
  ViewStack::set_visible_child_name (const Glib::ustring& name) -> void
  {
    adw_view_stack_set_visible_child_name (gobj (), name.c_str ());
  }

  auto
  ViewStack::property_hhomogeneous () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "hhomogeneous");
  }

  auto
  ViewStack::property_hhomogeneous () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "hhomogeneous");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Gtk::SelectionModel>>::value,
      "Type Glib::RefPtr<Gtk::SelectionModel> cannot be used in "
      "_WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  ViewStack::property_pages () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gtk::SelectionModel>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gtk::SelectionModel>> (
        this,
        "pages");
  }

  auto
  ViewStack::property_vhomogeneous () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "vhomogeneous");
  }

  auto
  ViewStack::property_vhomogeneous () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "vhomogeneous");
  }

  auto
  ViewStack::property_visible_child () -> Glib::PropertyProxy<Gtk::Widget*>
  {
    return Glib::PropertyProxy<Gtk::Widget*> (this, "visible-child");
  }

  auto
  ViewStack::property_visible_child () const -> Glib::PropertyProxy_ReadOnly<Gtk::Widget*>
  {
    return Glib::PropertyProxy_ReadOnly<Gtk::Widget*> (this, "visible-child");
  }

  auto
  ViewStack::property_visible_child_name () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "visible-child-name");
  }

  auto
  ViewStack::property_visible_child_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this,
                                                        "visible-child-name");
  }

} // namespace Adw
