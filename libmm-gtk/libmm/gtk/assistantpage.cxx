// SPDX-License-Identifier: LGPL-2.1-or-later

#undef GTK_DISABLE_DEPRECATED
#define GDK_DISABLE_DEPRECATION_WARNINGS 1

#include <libmm/gtk/mm-gtkconfig.hxx>
#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/mm-glib.hxx>

  #include <libmm/gtk/assistantpage.hxx>
  #include <libmm/gtk/assistantpage_p.hxx>

  #include <gtk/gtk.h>
  #include <libmm/gtk/widget.hxx>

using Type = gtk::AssistantPage::Type;

namespace
{
}

auto
glib::Value<gtk::AssistantPage::Type>::value_type () -> GType
{
  return gtk_assistant_page_type_get_type ();
}

namespace glib
{

  auto
  wrap (GtkAssistantPage* object, bool take_copy) -> glib::RefPtr<gtk::AssistantPage>
  {
    return glib::make_refptr_for_instance<gtk::AssistantPage> (
        dynamic_cast<gtk::AssistantPage*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  AssistantPage_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &AssistantPage_Class::class_init_function;

      register_derived_type (gtk_assistant_page_get_type ());
    }

    return *this;
  }

  auto
  AssistantPage_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  AssistantPage_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new AssistantPage ((GtkAssistantPage*) object);
  }

  auto
  AssistantPage::gobj_copy () -> GtkAssistantPage*
  {
    reference ();
    return gobj ();
  }

  AssistantPage::AssistantPage (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  AssistantPage::AssistantPage (GtkAssistantPage* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  AssistantPage::AssistantPage (AssistantPage&& src) noexcept
    : glib::Object (std::move (src))
  {
  }

  auto
  AssistantPage::operator= (AssistantPage&& src) noexcept -> AssistantPage&
  {
    glib::Object::operator= (std::move (src));
    return *this;
  }

  AssistantPage::~AssistantPage () noexcept {}

  AssistantPage::CppClassType AssistantPage::assistantpage_class_;

  auto
  AssistantPage::get_type () -> GType
  {
    return assistantpage_class_.init ().get_type ();
  }

  auto
  AssistantPage::get_base_type () -> GType
  {
    return gtk_assistant_page_get_type ();
  }

  auto
  AssistantPage::get_child () -> Widget*
  {
    return glib::wrap (gtk_assistant_page_get_child (gobj ()));
  }

  auto
  AssistantPage::get_child () const -> const Widget*
  {
    return const_cast<AssistantPage*> (this)->get_child ();
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<Type>::value,
      "Type Type cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  AssistantPage::property_page_type () -> glib::PropertyProxy<Type>
  {
    return glib::PropertyProxy<Type> (this, "page-type");
  }

  auto
  AssistantPage::property_page_type () const -> glib::PropertyProxy_ReadOnly<Type>
  {
    return glib::PropertyProxy_ReadOnly<Type> (this, "page-type");
  }

  auto
  AssistantPage::property_title () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "title");
  }

  auto
  AssistantPage::property_title () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "title");
  }

  auto
  AssistantPage::property_complete () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "complete");
  }

  auto
  AssistantPage::property_complete () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "complete");
  }

  auto
  AssistantPage::property_child () const -> glib::PropertyProxy_ReadOnly<Widget*>
  {
    return glib::PropertyProxy_ReadOnly<Widget*> (this, "child");
  }

} // namespace gtk

#endif
