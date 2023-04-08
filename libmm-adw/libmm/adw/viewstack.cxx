// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/viewstack.hxx>
#include <libmm/adw/viewstack_p.hxx>

#include <libmm/adw/selectionlistmodelimpl.hxx>
#include <libmm/gtk/mm-gtk.hxx>

namespace adw
{

  auto
  ViewStack::get_pages () const -> glib::RefPtr<gtk::SelectionModel>
  {
    GtkSelectionModel* pages =
        adw_view_stack_get_pages (const_cast<AdwViewStack*> (gobj ()));
    g_assert (G_IS_LIST_MODEL (pages));

    glib::ObjectBase* pCppObject =
        glib::ObjectBase::_get_current_wrapper ((GObject*) pages);
    if (!pCppObject)
      pCppObject = new adw::SelectionListModelImpl ((GObject*) pages);
    return glib::make_refptr_for_instance<gtk::SelectionModel> (
        dynamic_cast<gtk::SelectionModel*> (pCppObject));
  }

} // namespace adw

namespace
{
}

namespace glib
{

  auto
  wrap (AdwViewStack* object, bool take_copy) -> adw::ViewStack*
  {
    return dynamic_cast<adw::ViewStack*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace adw
{

  auto
  ViewStack_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_view_stack_get_type ();
    }

    return *this;
  }

  auto
  ViewStack_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new ViewStack ((AdwViewStack*) (o)));
  }

  ViewStack::ViewStack (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  ViewStack::ViewStack (AdwViewStack* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  ViewStack::ViewStack (ViewStack&& src) noexcept
    : gtk::Widget (std::move (src))
  {
  }

  auto
  ViewStack::operator= (ViewStack&& src) noexcept -> ViewStack&
  {
    gtk::Widget::operator= (std::move (src));
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
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (viewstack_class_.init ()))
  {
  }

  auto
  ViewStack::add (gtk::Widget* child) -> glib::RefPtr<ViewStackPage>
  {
    auto retvalue = glib::wrap (
        adw_view_stack_add (gobj (), (GtkWidget*) glib::unwrap (child)));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  ViewStack::add_named (gtk::Widget* child, const glib::ustring& name) -> glib::RefPtr<ViewStackPage>
  {
    auto retvalue =
        glib::wrap (adw_view_stack_add_named (gobj (),
                                              (GtkWidget*) glib::unwrap (child),
                                              name.c_str ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  ViewStack::add_titled (gtk::Widget* child,
                         const glib::ustring& name,
                         const glib::ustring& title) -> glib::RefPtr<ViewStackPage>
  {
    auto retvalue = glib::wrap (
        adw_view_stack_add_titled (gobj (),
                                   (GtkWidget*) glib::unwrap (child),
                                   name.c_str (),
                                   title.c_str ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  ViewStack::add_titled_with_icon (gtk::Widget* child,
                                   const glib::ustring& name,
                                   const glib::ustring& title,
                                   const glib::ustring& icon_name) -> glib::RefPtr<ViewStackPage>
  {
    auto retvalue = glib::wrap (
        adw_view_stack_add_titled_with_icon (gobj (),
                                             (GtkWidget*) glib::unwrap (child),
                                             name.c_str (),
                                             title.c_str (),
                                             icon_name.c_str ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  ViewStack::get_child_by_name (const glib::ustring& name) const -> gtk::Widget*
  {
    return glib::wrap (
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
  ViewStack::get_page (gtk::Widget* child) const -> glib::RefPtr<ViewStackPage>
  {
    auto retvalue = glib::wrap (
        adw_view_stack_get_page (const_cast<AdwViewStack*> (gobj ()),
                                 (GtkWidget*) glib::unwrap (child)));
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
  ViewStack::get_visible_child () const -> gtk::Widget*
  {
    return glib::wrap (
        adw_view_stack_get_visible_child (const_cast<AdwViewStack*> (gobj ())));
  }

  auto
  ViewStack::get_visible_child_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_view_stack_get_visible_child_name (
            const_cast<AdwViewStack*> (gobj ())));
  }

  auto
  ViewStack::remove (gtk::Widget* widget) -> void
  {
    adw_view_stack_remove (gobj (), (GtkWidget*) glib::unwrap (widget));
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
  ViewStack::set_visible_child (gtk::Widget* child) -> void
  {
    adw_view_stack_set_visible_child (gobj (),
                                      (GtkWidget*) glib::unwrap (child));
  }

  auto
  ViewStack::set_visible_child_name (const glib::ustring& name) -> void
  {
    adw_view_stack_set_visible_child_name (gobj (), name.c_str ());
  }

  auto
  ViewStack::property_hhomogeneous () -> glib::PropertyProxy<bool>
  {
    return {this, "hhomogeneous"};
  }

  auto
  ViewStack::property_hhomogeneous () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "hhomogeneous"};
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gtk::SelectionModel>>::value,
      "Type glib::RefPtr<gtk::SelectionModel> cannot be used in "
      "_WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  ViewStack::property_pages () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gtk::SelectionModel>>
  {
    return {
      this,
        "pages"
    };
  }

  auto
  ViewStack::property_vhomogeneous () -> glib::PropertyProxy<bool>
  {
    return {this, "vhomogeneous"};
  }

  auto
  ViewStack::property_vhomogeneous () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "vhomogeneous"};
  }

  auto
  ViewStack::property_visible_child () -> glib::PropertyProxy<gtk::Widget*>
  {
    return {this, "visible-child"};
  }

  auto
  ViewStack::property_visible_child () const -> glib::PropertyProxy_ReadOnly<gtk::Widget*>
  {
    return {this, "visible-child"};
  }

  auto
  ViewStack::property_visible_child_name () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "visible-child-name"};
  }

  auto
  ViewStack::property_visible_child_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "visible-child-name"};
  }

} // namespace adw
