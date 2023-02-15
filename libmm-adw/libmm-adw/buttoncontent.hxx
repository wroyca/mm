// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_BUTTONCONTENT_H
#define _LIBADWAITAMM_BUTTONCONTENT_H

#include <libmm-adw/mm-adwconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/mm-gtk.hxx>

#include <adwaita.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Adw
{
  class ButtonContent_Class;
}
#endif

namespace Adw
{

  class ButtonContent : public Gtk::Widget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef ButtonContent CppObjectType;
    typedef ButtonContent_Class CppClassType;
    typedef AdwButtonContent BaseObjectType;
    typedef AdwButtonContentClass BaseClassType;
#endif

    ButtonContent (ButtonContent&& src) noexcept;
    auto
    operator= (ButtonContent&& src) noexcept -> ButtonContent&;

    ButtonContent (const ButtonContent&) = delete;
    auto
    operator= (const ButtonContent&) -> ButtonContent& = delete;

    ~ButtonContent () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend class ButtonContent_Class;
    static CppClassType buttoncontent_class_;

  protected:
    explicit ButtonContent (const Glib::ConstructParams& construct_params);
    explicit ButtonContent (AdwButtonContent* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> AdwButtonContent*
    {
      return reinterpret_cast<AdwButtonContent*> (gobject_);
    }

    auto
    gobj () const -> const AdwButtonContent*
    {
      return reinterpret_cast<AdwButtonContent*> (gobject_);
    }

  private:
  public:
    ButtonContent ();

    auto
    get_icon_name () const -> Glib::ustring;

    auto
    get_label () const -> Glib::ustring;

    auto
    get_use_underline () const -> bool;

    auto
    set_icon_name (const Glib::ustring& icon_name) -> void;

    auto
    set_label (const Glib::ustring& label) -> void;

    auto
    set_use_underline (bool use_underline) -> void;

    auto
    property_icon_name () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_icon_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_label () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_label () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_use_underline () -> Glib::PropertyProxy<bool>;

    auto
    property_use_underline () const -> Glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace Adw

namespace Glib
{

  auto
  wrap (AdwButtonContent* object, bool take_copy = false) -> Adw::ButtonContent*;
}

#endif
