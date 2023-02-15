// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_PROGRESSBAR_H
#define _GTKMM_PROGRESSBAR_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/orientable.hxx>
#include <libmm-gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkProgressBar = struct _GtkProgressBar;
using GtkProgressBarClass = struct _GtkProgressBarClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class ProgressBar_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API ProgressBar : public Widget,
                                public Orientable
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef ProgressBar CppObjectType;
    typedef ProgressBar_Class CppClassType;
    typedef GtkProgressBar BaseObjectType;
    typedef GtkProgressBarClass BaseClassType;
#endif

    ProgressBar (ProgressBar&& src) noexcept;
    auto
    operator= (ProgressBar&& src) noexcept -> ProgressBar&;

    ProgressBar (const ProgressBar&) = delete;
    auto
    operator= (const ProgressBar&) -> ProgressBar& = delete;

    ~ProgressBar () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend class ProgressBar_Class;
    static CppClassType progressbar_class_;

  protected:
    explicit ProgressBar (const Glib::ConstructParams& construct_params);
    explicit ProgressBar (GtkProgressBar* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkProgressBar*
    {
      return reinterpret_cast<GtkProgressBar*> (gobject_);
    }

    auto
    gobj () const -> const GtkProgressBar*
    {
      return reinterpret_cast<GtkProgressBar*> (gobject_);
    }

  private:
  public:
    ProgressBar ();

    auto
    pulse () -> void;

    auto
    get_text () const -> Glib::ustring;

    auto
    set_text (const Glib::ustring& text) -> void;

    auto
    get_fraction () const -> double;

    auto
    set_fraction (double fraction) -> void;

    auto
    get_pulse_step () const -> double;

    auto
    set_pulse_step (double fraction) -> void;

    auto
    set_inverted (bool inverted = true) -> void;

    auto
    get_inverted () const -> bool;

    auto
    set_ellipsize (Pango::EllipsizeMode mode) -> void;

    auto
    get_ellipsize () const -> Pango::EllipsizeMode;

    auto
    set_show_text (bool show_text = true) -> void;

    auto
    get_show_text () const -> bool;

    auto
    property_fraction () -> Glib::PropertyProxy<double>;

    auto
    property_fraction () const -> Glib::PropertyProxy_ReadOnly<double>;

    auto
    property_pulse_step () -> Glib::PropertyProxy<double>;

    auto
    property_pulse_step () const -> Glib::PropertyProxy_ReadOnly<double>;

    auto
    property_text () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_text () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_ellipsize () -> Glib::PropertyProxy<bool>;

    auto
    property_ellipsize () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_show_text () -> Glib::PropertyProxy<bool>;

    auto
    property_show_text () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_inverted () -> Glib::PropertyProxy<bool>;

    auto
    property_inverted () const -> Glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  auto
  wrap (GtkProgressBar* object, bool take_copy = false) -> Gtk::ProgressBar*;
}

#endif
