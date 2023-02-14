// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/assistantpage.hxx>
#include <libmm-gtk/assistantpage_p.hxx>

#include <gtk/gtk.h>
#include <libmm-gtk/widget.hxx>

using Type = Gtk::AssistantPage::Type;

namespace
{
}

auto
Glib::Value<Gtk::AssistantPage::Type>::value_type () -> GType
{
  return gtk_assistant_page_type_get_type ();
}

namespace Glib
{

  auto
  wrap (GtkAssistantPage* object, const bool take_copy) -> RefPtr<Gtk::AssistantPage>
  {
    return Glib::make_refptr_for_instance<Gtk::AssistantPage> (
        dynamic_cast<Gtk::AssistantPage*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  AssistantPage_Class::init () -> const Class&
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
  AssistantPage_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new AssistantPage ((GtkAssistantPage*) object);
  }

  auto
  AssistantPage::gobj_copy () -> GtkAssistantPage*
  {
    reference ();
    return gobj ();
  }

  AssistantPage::AssistantPage (const Glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  AssistantPage::AssistantPage (GtkAssistantPage* castitem)
    : Object ((GObject*) castitem)
  {
  }

  AssistantPage::AssistantPage (AssistantPage&& src) noexcept
    : Object (std::move (src))
  {
  }

  auto
  AssistantPage::operator= (AssistantPage&& src) noexcept -> AssistantPage&
  {
    Object::operator= (std::move (src));
    return *this;
  }

  AssistantPage::~AssistantPage () noexcept = default;

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
    return Glib::wrap (gtk_assistant_page_get_child (gobj ()));
  }

  auto
  AssistantPage::get_child () const -> const Widget*
  {
    return const_cast<AssistantPage*> (this)->get_child ();
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Type>::value,
      "Type Type cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  AssistantPage::property_page_type () -> Glib::PropertyProxy<Type>
  {
    return {this, "page-type"};
  }

  auto
  AssistantPage::property_page_type () const -> Glib::PropertyProxy_ReadOnly<Type>
  {
    return {this, "page-type"};
  }

  auto
  AssistantPage::property_title () -> Glib::PropertyProxy<Glib::ustring>
  {
    return {this, "title"};
  }

  auto
  AssistantPage::property_title () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return {this, "title"};
  }

  auto
  AssistantPage::property_complete () -> Glib::PropertyProxy<bool>
  {
    return {this, "complete"};
  }

  auto
  AssistantPage::property_complete () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "complete"};
  }

  auto
  AssistantPage::property_child () const -> Glib::PropertyProxy_ReadOnly<Widget*>
  {
    return {this, "child"};
  }

} // namespace Gtk
