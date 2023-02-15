// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_ASSISTANTPAGE_H
#define _GTKMM_ASSISTANTPAGE_H

#include <libmm-gtk/mm-gtkconfig.hxx>

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm-glib/ustring.hxx>
  #include <sigc++/sigc++.h>

  #include <libmm-glib/object.hxx>
  #include <libmm-glib/refptr.hxx>

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkAssistantPage = struct _GtkAssistantPage;
using GtkAssistantPageClass = struct _GtkAssistantPageClass;
  #endif

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API AssistantPage_Class;
}
  #endif

namespace Gtk
{
  class GTKMM_API Widget;

  class GTKMM_API AssistantPage : public Glib::Object
  {
  #ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = AssistantPage;
    using CppClassType = AssistantPage_Class;
    using BaseObjectType = GtkAssistantPage;
    using BaseClassType = GtkAssistantPageClass;

    AssistantPage (const AssistantPage&) = delete;
    auto
    operator= (const AssistantPage&) -> AssistantPage& = delete;

  private:
    friend class AssistantPage_Class;
    static CppClassType assistantpage_class_;

  protected:
    explicit AssistantPage (const Glib::ConstructParams& construct_params);
    explicit AssistantPage (GtkAssistantPage* castitem);

  #endif

  public:
    AssistantPage (AssistantPage&& src) noexcept;
    auto
    operator= (AssistantPage&& src) noexcept -> AssistantPage&;

    ~AssistantPage () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

  #ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
  #endif

    auto
    gobj () -> GtkAssistantPage*
    {
      return reinterpret_cast<GtkAssistantPage*> (gobject_);
    }

    auto
    gobj () const -> const GtkAssistantPage*
    {
      return reinterpret_cast<GtkAssistantPage*> (gobject_);
    }

    auto
    gobj_copy () -> GtkAssistantPage*;

  private:
  public:
    enum class Type
    {
      CONTENT,
      INTRO,
      CONFIRM,
      SUMMARY,
      PROGRESS,
      CUSTOM
    };

    auto
    get_child () -> Widget*;

    auto
    get_child () const -> const Widget*;

    auto
    property_page_type () -> Glib::PropertyProxy<Type>;

    auto
    property_page_type () const -> Glib::PropertyProxy_ReadOnly<Type>;

    auto
    property_title () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_title () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_complete () -> Glib::PropertyProxy<bool>;

    auto
    property_complete () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_child () const -> Glib::PropertyProxy_ReadOnly<Widget*>;

  public:
  public:
  protected:
  };

} // namespace Gtk

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GTKMM_API Value<Gtk::AssistantPage::Type>
    : public Glib::Value_Enum<Gtk::AssistantPage::Type>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
  #endif

namespace Glib
{
  GTKMM_API auto
  wrap (GtkAssistantPage* object, bool take_copy = false) -> Glib::RefPtr<Gtk::AssistantPage>;
} // namespace Glib

#endif

#endif
