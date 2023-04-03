// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/stackpage.hxx>
#include <libmm/gtk/stackpage_p.hxx>

#include <gtk/gtk.h>
#include <libmm/gtk/widget.hxx>

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkStackPage* object, bool take_copy) -> Glib::RefPtr<Gtk::StackPage>
  {
    return Glib::make_refptr_for_instance<Gtk::StackPage> (
        dynamic_cast<Gtk::StackPage*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  StackPage_Class::init () -> const Glib::Class&
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
  StackPage_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new StackPage ((GtkStackPage*) object);
  }

  auto
  StackPage::gobj_copy () -> GtkStackPage*
  {
    reference ();
    return gobj ();
  }

  StackPage::StackPage (const Glib::ConstructParams& construct_params)
    : Glib::Object (construct_params)
  {
  }

  StackPage::StackPage (GtkStackPage* castitem)
    : Glib::Object ((GObject*) (castitem))
  {
  }

  StackPage::StackPage (StackPage&& src) noexcept
    : Glib::Object (std::move (src)),
      Accessible (std::move (src))
  {
  }

  auto
  StackPage::operator= (StackPage&& src) noexcept -> StackPage&
  {
    Glib::Object::operator= (std::move (src));
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
    return Glib::wrap (gtk_stack_page_get_child (gobj ()));
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
  StackPage::get_name () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        gtk_stack_page_get_name (const_cast<GtkStackPage*> (gobj ())));
  }

  auto
  StackPage::set_name (const Glib::ustring& setting) -> void
  {
    gtk_stack_page_set_name (gobj (), setting.c_str ());
  }

  auto
  StackPage::get_title () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        gtk_stack_page_get_title (const_cast<GtkStackPage*> (gobj ())));
  }

  auto
  StackPage::set_title (const Glib::ustring& setting) -> void
  {
    gtk_stack_page_set_title (gobj (), setting.c_str ());
  }

  auto
  StackPage::get_icon_name () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        gtk_stack_page_get_icon_name (const_cast<GtkStackPage*> (gobj ())));
  }

  auto
  StackPage::set_icon_name (const Glib::ustring& setting) -> void
  {
    gtk_stack_page_set_icon_name (gobj (), setting.c_str ());
  }

  auto
  StackPage::property_child () const -> Glib::PropertyProxy_ReadOnly<Widget*>
  {
    return Glib::PropertyProxy_ReadOnly<Widget*> (this, "child");
  }

  auto
  StackPage::property_name () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "name");
  }

  auto
  StackPage::property_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "name");
  }

  auto
  StackPage::property_title () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "title");
  }

  auto
  StackPage::property_title () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "title");
  }

  auto
  StackPage::property_icon_name () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "icon-name");
  }

  auto
  StackPage::property_icon_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "icon-name");
  }

  auto
  StackPage::property_needs_attention () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "needs-attention");
  }

  auto
  StackPage::property_needs_attention () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "needs-attention");
  }

  auto
  StackPage::property_visible () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "visible");
  }

  auto
  StackPage::property_visible () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "visible");
  }

  auto
  StackPage::property_use_underline () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "use-underline");
  }

  auto
  StackPage::property_use_underline () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "use-underline");
  }

} // namespace Gtk