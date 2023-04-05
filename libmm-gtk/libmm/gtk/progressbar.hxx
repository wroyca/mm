// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_PROGRESSBAR_H
#define _GTKMM_PROGRESSBAR_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/orientable.hxx>
#include <libmm/gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkProgressBar = struct _GtkProgressBar;
using GtkProgressBarClass = struct _GtkProgressBarClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class ProgressBar_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT ProgressBar : public Widget,
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
    explicit ProgressBar (const glib::ConstructParams& construct_params);
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
    get_text () const -> glib::ustring;

    auto
    set_text (const glib::ustring& text) -> void;

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
    set_ellipsize (pango::EllipsizeMode mode) -> void;

    auto
    get_ellipsize () const -> pango::EllipsizeMode;

    auto
    set_show_text (bool show_text = true) -> void;

    auto
    get_show_text () const -> bool;

    auto
    property_fraction () -> glib::PropertyProxy<double>;

    auto
    property_fraction () const -> glib::PropertyProxy_ReadOnly<double>;

    auto
    property_pulse_step () -> glib::PropertyProxy<double>;

    auto
    property_pulse_step () const -> glib::PropertyProxy_ReadOnly<double>;

    auto
    property_text () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_text () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_ellipsize () -> glib::PropertyProxy<bool>;

    auto
    property_ellipsize () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_show_text () -> glib::PropertyProxy<bool>;

    auto
    property_show_text () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_inverted () -> glib::PropertyProxy<bool>;

    auto
    property_inverted () const -> glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{

  auto
  wrap (GtkProgressBar* object, bool take_copy = false) -> gtk::ProgressBar*;
}

#endif
