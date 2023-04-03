// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_TOAST_H
#define _LIBADWAITAMM_TOAST_H

#include <libmm/adw/mm-adwconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/glib/mm-glib.hxx>
#include <libmm/gtk/mm-gtk.hxx>

#include <adwaita.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Adw
{
  class LIBMM_ADW_SYMEXPORT Toast_Class;
}
#endif

namespace Adw
{

  enum class LIBMM_ADW_SYMEXPORT ToastPriority
  {
    NORMAL,
    HIGH
  };

} // namespace Adw

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class LIBMM_ADW_SYMEXPORT Value<Adw::ToastPriority> : public Glib::Value_Enum<Adw::ToastPriority>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Adw
{

  class LIBMM_ADW_SYMEXPORT Toast : public Glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Toast;
    using CppClassType = Toast_Class;
    using BaseObjectType = AdwToast;
    using BaseClassType = AdwToastClass;

    Toast (const Toast&) = delete;
    auto
    operator= (const Toast&) -> Toast& = delete;

  private:
    friend class Toast_Class;
    static CppClassType toast_class_;

  protected:
    explicit Toast (const Glib::ConstructParams& construct_params);
    explicit Toast (AdwToast* castitem);

#endif

  public:
    Toast (Toast&& src) noexcept;
    auto
    operator= (Toast&& src) noexcept -> Toast&;

    ~Toast () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> AdwToast*
    {
      return reinterpret_cast<AdwToast*> (gobject_);
    }

    auto
    gobj () const -> const AdwToast*
    {
      return reinterpret_cast<AdwToast*> (gobject_);
    }

    auto
    gobj_copy () -> AdwToast*;

  private:
  protected:
    Toast ();

  public:
    explicit Toast (const Glib::ustring& title);

    auto
    dismiss () -> void;

    auto
    get_action_name () const -> Glib::ustring;

    auto
    get_button_label () const -> Glib::ustring;

    auto
    get_custom_title () const -> Gtk::Widget*;

    auto
    get_priority () const -> ToastPriority;

    auto
    get_timeout () const -> guint;

    auto
    get_title () const -> Glib::ustring;

    auto
    set_action_name (const Glib::ustring& action_name) -> void;

    auto
    set_button_label (const Glib::ustring& button_label) -> void;

    auto
    set_custom_title (Gtk::Widget* widget) -> void;

    auto
    set_detailed_action_name (const Glib::ustring& detailed_action_name)
        -> void;

    auto
    set_priority (ToastPriority priority) -> void;

    auto
    set_timeout (guint timeout) -> void;

    auto
    set_title (const Glib::ustring& title) -> void;

    auto
    get_action_target_value () const -> Glib::VariantBase;

    auto
    set_action_target_value (const Glib::VariantBase& target_value) -> void;

    auto
    property_action_name () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_action_name () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_action_target () -> Glib::PropertyProxy<Glib::VariantBase>;

    auto
    property_action_target () const
        -> Glib::PropertyProxy_ReadOnly<Glib::VariantBase>;

    auto
    property_button_label () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_button_label () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_custom_title () -> Glib::PropertyProxy<Gtk::Widget*>;

    auto
    property_custom_title () const
        -> Glib::PropertyProxy_ReadOnly<Gtk::Widget*>;

    auto
    property_priority () -> Glib::PropertyProxy<ToastPriority>;

    auto
    property_priority () const -> Glib::PropertyProxy_ReadOnly<ToastPriority>;

    auto
    property_timeout () -> Glib::PropertyProxy<guint>;

    auto
    property_timeout () const -> Glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_title () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_title () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    signal_button_clicked () -> Glib::SignalProxy<void ()>;

    auto
    signal_dismissed () -> Glib::SignalProxy<void ()>;

  public:
  public:
  protected:
  };

} // namespace Adw

namespace Glib
{

  auto
  wrap (AdwToast* object, bool take_copy = false) -> Glib::RefPtr<Adw::Toast>;
}

#endif
