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
namespace adw
{
  class LIBMM_ADW_SYMEXPORT toast_class;
}
#endif

namespace adw
{

  enum class LIBMM_ADW_SYMEXPORT ToastPriority
  {
    NORMAL,
    HIGH
  };

} // namespace adw

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_ADW_SYMEXPORT Value<adw::ToastPriority> : public glib::Value_Enum<adw::ToastPriority>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace adw
{

  class LIBMM_ADW_SYMEXPORT toast : public glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = toast;
    using CppClassType = toast_class;
    using BaseObjectType = AdwToast;
    using BaseClassType = AdwToastClass;

    toast (const toast&) = delete;
    auto
    operator= (const toast&) -> toast& = delete;

  private:
    friend class toast_class;
    static CppClassType toast_class_;

  protected:
    explicit toast (const glib::ConstructParams& construct_params);
    explicit toast (AdwToast* castitem);

#endif

  public:
    toast (toast&& src) noexcept;
    auto
    operator= (toast&& src) noexcept -> toast&;

    ~toast () noexcept override;

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
    toast ();

  public:
    explicit toast (const glib::ustring& title);

    auto
    dismiss () -> void;

    auto
    get_action_name () const -> glib::ustring;

    auto
    get_button_label () const -> glib::ustring;

    auto
    get_custom_title () const -> gtk::Widget*;

    auto
    get_priority () const -> ToastPriority;

    auto
    get_timeout () const -> guint;

    auto
    get_title () const -> glib::ustring;

    auto
    set_action_name (const glib::ustring& action_name) -> void;

    auto
    set_button_label (const glib::ustring& button_label) -> void;

    auto
    set_custom_title (gtk::Widget* widget) -> void;

    auto
    set_detailed_action_name (const glib::ustring& detailed_action_name)
        -> void;

    auto
    set_priority (ToastPriority priority) -> void;

    auto
    set_timeout (guint timeout) -> void;

    auto
    set_title (const glib::ustring& title) -> void;

    auto
    get_action_target_value () const -> glib::VariantBase;

    auto
    set_action_target_value (const glib::VariantBase& target_value) -> void;

    auto
    property_action_name () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_action_name () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_action_target () -> glib::PropertyProxy<glib::VariantBase>;

    auto
    property_action_target () const
        -> glib::PropertyProxy_ReadOnly<glib::VariantBase>;

    auto
    property_button_label () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_button_label () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_custom_title () -> glib::PropertyProxy<gtk::Widget*>;

    auto
    property_custom_title () const
        -> glib::PropertyProxy_ReadOnly<gtk::Widget*>;

    auto
    property_priority () -> glib::PropertyProxy<ToastPriority>;

    auto
    property_priority () const -> glib::PropertyProxy_ReadOnly<ToastPriority>;

    auto
    property_timeout () -> glib::PropertyProxy<guint>;

    auto
    property_timeout () const -> glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_title () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_title () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    signal_button_clicked () -> glib::SignalProxy<void ()>;

    auto
    signal_dismissed () -> glib::SignalProxy<void ()>;

  public:
  public:
  protected:
  };

} // namespace adw

namespace glib
{

  auto
  wrap (AdwToast* object, bool take_copy = false) -> glib::RefPtr<adw::toast>;
}

#endif
