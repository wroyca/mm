// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/stackpage.hxx>
#include <libmm/gtk/stackpage_p.hxx>

#include <gtk/gtk.h>
#include <libmm/gtk/widget.hxx>

namespace
{
}

namespace glib
{

  auto
  wrap (GtkStackPage* object, bool take_copy) -> glib::RefPtr<gtk::StackPage>
  {
    return glib::make_refptr_for_instance<gtk::StackPage> (
        dynamic_cast<gtk::StackPage*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  StackPage_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &StackPage_Class::class_init_function;

      register_derived_type (gtk_stack_page_get_type ());

      Accessible::add_interface (get_type ());
    }

    return *this;
  }

  auto
  StackPage_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  StackPage_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new StackPage ((GtkStackPage*) object);
  }

  auto
  StackPage::gobj_copy () -> GtkStackPage*
  {
    reference ();
    return gobj ();
  }

  StackPage::StackPage (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  StackPage::StackPage (GtkStackPage* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  StackPage::StackPage (StackPage&& src) noexcept
    : glib::Object (std::move (src)),
      Accessible (std::move (src))
  {
  }

  auto
  StackPage::operator= (StackPage&& src) noexcept -> StackPage&
  {
    glib::Object::operator= (std::move (src));
    Accessible::operator= (std::move (src));
    return *this;
  }

  StackPage::~StackPage () noexcept {}

  StackPage::CppClassType StackPage::stackpage_class_;

  auto
  StackPage::get_type () -> GType
  {
    return stackpage_class_.init ().get_type ();
  }

  auto
  StackPage::get_base_type () -> GType
  {
    return gtk_stack_page_get_type ();
  }

  auto
  StackPage::get_child () -> Widget*
  {
    return glib::wrap (gtk_stack_page_get_child (gobj ()));
  }

  auto
  StackPage::get_child () const -> const Widget*
  {
    return const_cast<StackPage*> (this)->get_child ();
  }

  auto
  StackPage::get_visible () const -> bool
  {
    return gtk_stack_page_get_visible (const_cast<GtkStackPage*> (gobj ()));
  }

  auto
  StackPage::set_visible (bool visible) -> void
  {
    gtk_stack_page_set_visible (gobj (), static_cast<int> (visible));
  }

  auto
  StackPage::get_needs_attention () const -> bool
  {
    return gtk_stack_page_get_needs_attention (
        const_cast<GtkStackPage*> (gobj ()));
  }

  auto
  StackPage::set_needs_attention (bool setting) -> void
  {
    gtk_stack_page_set_needs_attention (gobj (), static_cast<int> (setting));
  }

  auto
  StackPage::get_use_underline () const -> bool
  {
    return gtk_stack_page_get_use_underline (
        const_cast<GtkStackPage*> (gobj ()));
  }

  auto
  StackPage::set_use_underline (bool setting) -> void
  {
    gtk_stack_page_set_use_underline (gobj (), static_cast<int> (setting));
  }

  auto
  StackPage::get_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_stack_page_get_name (const_cast<GtkStackPage*> (gobj ())));
  }

  auto
  StackPage::set_name (const glib::ustring& setting) -> void
  {
    gtk_stack_page_set_name (gobj (), setting.c_str ());
  }

  auto
  StackPage::get_title () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_stack_page_get_title (const_cast<GtkStackPage*> (gobj ())));
  }

  auto
  StackPage::set_title (const glib::ustring& setting) -> void
  {
    gtk_stack_page_set_title (gobj (), setting.c_str ());
  }

  auto
  StackPage::get_icon_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_stack_page_get_icon_name (const_cast<GtkStackPage*> (gobj ())));
  }

  auto
  StackPage::set_icon_name (const glib::ustring& setting) -> void
  {
    gtk_stack_page_set_icon_name (gobj (), setting.c_str ());
  }

  auto
  StackPage::property_child () const -> glib::PropertyProxy_ReadOnly<Widget*>
  {
    return glib::PropertyProxy_ReadOnly<Widget*> (this, "child");
  }

  auto
  StackPage::property_name () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "name");
  }

  auto
  StackPage::property_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "name");
  }

  auto
  StackPage::property_title () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "title");
  }

  auto
  StackPage::property_title () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "title");
  }

  auto
  StackPage::property_icon_name () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "icon-name");
  }

  auto
  StackPage::property_icon_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "icon-name");
  }

  auto
  StackPage::property_needs_attention () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "needs-attention");
  }

  auto
  StackPage::property_needs_attention () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "needs-attention");
  }

  auto
  StackPage::property_visible () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "visible");
  }

  auto
  StackPage::property_visible () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "visible");
  }

  auto
  StackPage::property_use_underline () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "use-underline");
  }

  auto
  StackPage::property_use_underline () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "use-underline");
  }

} // namespace gtk
