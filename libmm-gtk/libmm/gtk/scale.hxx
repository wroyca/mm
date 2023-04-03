// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_SCALE_H
#define _GTKMM_SCALE_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/range.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkScale = struct _GtkScale;
using GtkScaleClass = struct _GtkScaleClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT Scale_Class;
}
#endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT Scale : public Range
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef Scale CppObjectType;
    typedef Scale_Class CppClassType;
    typedef GtkScale BaseObjectType;
    typedef GtkScaleClass BaseClassType;
#endif

    Scale (Scale&& src) noexcept;
    auto
    operator= (Scale&& src) noexcept -> Scale&;

    Scale (const Scale&) = delete;
    auto
    operator= (const Scale&) -> Scale& = delete;

    ~Scale () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class Scale_Class;
    static CppClassType scale_class_;

  protected:
    explicit Scale (const Glib::ConstructParams& construct_params);
    explicit Scale (GtkScale* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkScale*
    {
      return reinterpret_cast<GtkScale*> (gobject_);
    }

    auto
    gobj () const -> const GtkScale*
    {
      return reinterpret_cast<GtkScale*> (gobject_);
    }

  private:
  public:
    Scale ();

    explicit Scale (Orientation orientation);

    explicit Scale (const Glib::RefPtr<Adjustment>& adjustment,
                    Orientation orientation = Orientation::HORIZONTAL);

    auto
    set_digits (int digits) -> void;

    auto
    get_digits () const -> int;

    auto
    set_draw_value (bool draw_value = true) -> void;

    auto
    get_draw_value () const -> bool;

    auto
    set_value_pos (PositionType pos) -> void;

    auto
    get_value_pos () const -> PositionType;

    auto
    set_has_origin (bool has_origin = true) -> void;

    auto
    get_has_origin () const -> bool;

    auto
    get_layout () -> Glib::RefPtr<Pango::Layout>;

    auto
    get_layout () const -> Glib::RefPtr<const Pango::Layout>;

    auto
    get_layout_offsets (int& x, int& y) const -> void;

    auto
    add_mark (double value, PositionType position, const Glib::ustring& markup)
        -> void;

    auto
    clear_marks () -> void;

    using SlotFormatValue = sigc::slot<Glib::ustring (double)>;

    auto
    set_format_value_func (const SlotFormatValue& slot) -> void;

    auto
    unset_format_value_func () -> void;

    auto
    property_digits () -> Glib::PropertyProxy<int>;

    auto
    property_digits () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_draw_value () -> Glib::PropertyProxy<bool>;

    auto
    property_draw_value () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_value_pos () -> Glib::PropertyProxy<PositionType>;

    auto
    property_value_pos () const -> Glib::PropertyProxy_ReadOnly<PositionType>;

    auto
    property_has_origin () -> Glib::PropertyProxy<bool>;

    auto
    property_has_origin () const -> Glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkScale* object, bool take_copy = false) -> Gtk::Scale*;
} // namespace Glib

#endif
