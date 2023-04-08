// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/viewstack.hxx>
#include <libmm/adw/viewstack_p.hxx>

#include <libmm/adw/selectionlistmodelimpl.hxx>
#include <libmm/gtk/mm-gtk.hxx>

namespace adw
{

  auto
  view_stack::get_pages () const -> glib::RefPtr<gtk::SelectionModel>
  {
    GtkSelectionModel* pages =
        adw_view_stack_get_pages (const_cast<AdwViewStack*> (gobj ()));
    g_assert (G_IS_LIST_MODEL (pages));

    glib::ObjectBase* pCppObject =
        glib::ObjectBase::_get_current_wrapper ((GObject*) pages);
    if (!pCppObject)
      pCppObject = new adw::selection_list_model_impl ((GObject*) pages);
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
  wrap (AdwViewStack* object, bool take_copy) -> adw::view_stack*
  {
    return dynamic_cast<adw::view_stack*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace adw
{

  auto
  view_stack_class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_view_stack_get_type ();
    }

    return *this;
  }

  auto
  view_stack_class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new view_stack ((AdwViewStack*) (o)));
  }

  view_stack::view_stack (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  view_stack::view_stack (AdwViewStack* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  view_stack::view_stack (view_stack&& src) noexcept
    : gtk::Widget (std::move (src))
  {
  }

  auto
  view_stack::operator= (view_stack&& src) noexcept -> view_stack&
  {
    gtk::Widget::operator= (std::move (src));
    return *this;
  }

  view_stack::~view_stack () noexcept
  {
    destroy_ ();
  }

  view_stack::CppClassType view_stack::viewstack_class_;

  auto
  view_stack::get_type () -> GType
  {
    return viewstack_class_.init ().get_type ();
  }

  auto
  view_stack::get_base_type () -> GType
  {
    return adw_view_stack_get_type ();
  }

  view_stack::view_stack ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (viewstack_class_.init ()))
  {
  }

  auto
  view_stack::add (gtk::Widget* child) -> glib::RefPtr<view_stack_page>
  {
    auto retvalue = glib::wrap (
        adw_view_stack_add (gobj (), (GtkWidget*) glib::unwrap (child)));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  view_stack::add_named (gtk::Widget* child, const glib::ustring& name) -> glib::RefPtr<view_stack_page>
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
  view_stack::add_titled (gtk::Widget* child,
                         const glib::ustring& name,
                         const glib::ustring& title) -> glib::RefPtr<view_stack_page>
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
  view_stack::add_titled_with_icon (gtk::Widget* child,
                                   const glib::ustring& name,
                                   const glib::ustring& title,
                                   const glib::ustring& icon_name) -> glib::RefPtr<view_stack_page>
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
  view_stack::get_child_by_name (const glib::ustring& name) const -> gtk::Widget*
  {
    return glib::wrap (
        adw_view_stack_get_child_by_name (const_cast<AdwViewStack*> (gobj ()),
                                          name.c_str ()));
  }

  auto
  view_stack::get_hhomogeneous () const -> bool
  {
    return adw_view_stack_get_hhomogeneous (
        const_cast<AdwViewStack*> (gobj ()));
  }

  auto
  view_stack::get_page (gtk::Widget* child) const -> glib::RefPtr<view_stack_page>
  {
    auto retvalue = glib::wrap (
        adw_view_stack_get_page (const_cast<AdwViewStack*> (gobj ()),
                                 (GtkWidget*) glib::unwrap (child)));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  view_stack::get_vhomogeneous () const -> bool
  {
    return adw_view_stack_get_vhomogeneous (
        const_cast<AdwViewStack*> (gobj ()));
  }

  auto
  view_stack::get_visible_child () const -> gtk::Widget*
  {
    return glib::wrap (
        adw_view_stack_get_visible_child (const_cast<AdwViewStack*> (gobj ())));
  }

  auto
  view_stack::get_visible_child_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_view_stack_get_visible_child_name (
            const_cast<AdwViewStack*> (gobj ())));
  }

  auto
  view_stack::remove (gtk::Widget* widget) -> void
  {
    adw_view_stack_remove (gobj (), (GtkWidget*) glib::unwrap (widget));
  }

  auto
  view_stack::set_hhomogeneous (bool hhomogeneous) -> void
  {
    adw_view_stack_set_hhomogeneous (gobj (), static_cast<int> (hhomogeneous));
  }

  auto
  view_stack::set_vhomogeneous (bool hhomogeneous) -> void
  {
    adw_view_stack_set_vhomogeneous (gobj (), static_cast<int> (hhomogeneous));
  }

  auto
  view_stack::set_visible_child (gtk::Widget* child) -> void
  {
    adw_view_stack_set_visible_child (gobj (),
                                      (GtkWidget*) glib::unwrap (child));
  }

  auto
  view_stack::set_visible_child_name (const glib::ustring& name) -> void
  {
    adw_view_stack_set_visible_child_name (gobj (), name.c_str ());
  }

  auto
  view_stack::property_hhomogeneous () -> glib::PropertyProxy<bool>
  {
    return {this, "hhomogeneous"};
  }

  auto
  view_stack::property_hhomogeneous () const -> glib::PropertyProxy_ReadOnly<bool>
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
  view_stack::property_pages () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gtk::SelectionModel>>
  {
    return {
      this,
        "pages"
    };
  }

  auto
  view_stack::property_vhomogeneous () -> glib::PropertyProxy<bool>
  {
    return {this, "vhomogeneous"};
  }

  auto
  view_stack::property_vhomogeneous () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "vhomogeneous"};
  }

  auto
  view_stack::property_visible_child () -> glib::PropertyProxy<gtk::Widget*>
  {
    return {this, "visible-child"};
  }

  auto
  view_stack::property_visible_child () const -> glib::PropertyProxy_ReadOnly<gtk::Widget*>
  {
    return {this, "visible-child"};
  }

  auto
  view_stack::property_visible_child_name () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "visible-child-name"};
  }

  auto
  view_stack::property_visible_child_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "visible-child-name"};
  }

} // namespace adw
