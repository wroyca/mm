// SPDX-License-Identifier: LGPL-2.0-or-later

#ifndef _PANGOMM_CONTEXT_H
#define _PANGOMM_CONTEXT_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/cairo/context.hxx>
#include <libmm/cairo/fontoptions.hxx>
#include <libmm/glib/object.hxx>
#include <libmm/pango/attrlist.hxx>
#include <libmm/pango/fontdescription.hxx>
#include <libmm/pango/fontmap.hxx>
#include <libmm/pango/fontmetrics.hxx>
#include <libmm/pango/fontset.hxx>
#include <libmm/pango/item.hxx>
#include <libmm/pango/types.hxx>
#include <pango/pango.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using PangoContext = struct _PangoContext;
using PangoContextClass = struct _PangoContextClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace pango
{
  class LIBMM_PANGO_SYMEXPORT Context_Class;
}
#endif

namespace pango
{

  enum class Direction
  {
    LTR,
    RTL,
    TTB_LTR,
    TTB_RTL,
    WEAK_LTR,
    WEAK_RTL,
    NEUTRAL
  };

} // namespace pango

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_PANGO_SYMEXPORT Value<pango::Direction>
    : public glib::Value_Enum<pango::Direction>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace pango
{

  enum class GravityHint
  {
    NATURAL,
    STRONG,
    LINE
  };

} // namespace pango

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_PANGO_SYMEXPORT Value<pango::GravityHint>
    : public glib::Value_Enum<pango::GravityHint>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace pango
{

  class LIBMM_PANGO_SYMEXPORT Context : public glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Context;
    using CppClassType = Context_Class;
    using BaseObjectType = PangoContext;
    using BaseClassType = PangoContextClass;

    Context (const Context&) = delete;
    auto
    operator= (const Context&) -> Context& = delete;

  private:
    friend class Context_Class;
    static CppClassType context_class_;

  protected:
    explicit Context (const glib::ConstructParams& construct_params);
    explicit Context (PangoContext* castitem);

#endif

  public:
    Context (Context&& src) noexcept;
    auto
    operator= (Context&& src) noexcept -> Context&;

    ~Context () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> PangoContext*
    {
      return reinterpret_cast<PangoContext*> (gobject_);
    }

    auto
    gobj () const -> const PangoContext*
    {
      return reinterpret_cast<PangoContext*> (gobject_);
    }

    auto
    gobj_copy () -> PangoContext*;

  private:
  protected:
    Context ();

  public:
    auto
    list_families () const -> std::vector<glib::RefPtr<FontFamily>>;

    auto
    set_font_map (const glib::RefPtr<FontMap>& font_map) -> void;

    auto
    get_font_map () -> glib::RefPtr<FontMap>;

    auto
    get_font_map () const -> glib::RefPtr<const FontMap>;

    auto
    get_serial () const -> guint;

    auto
    load_font (const FontDescription& desc) const -> glib::RefPtr<Font>;

    auto
    load_fontset (const FontDescription& desc, const Language& language) const
        -> glib::RefPtr<Fontset>;

    auto
    get_metrics (const FontDescription& desc) const -> FontMetrics;

    auto
    get_metrics (const FontDescription& desc, const Language& language) const
        -> FontMetrics;

    auto
    set_font_description (const FontDescription& desc) -> void;

    auto
    get_font_description () const -> FontDescription;

    auto
    get_language () const -> Language;

    auto
    set_language (const Language& language) -> void;

    auto
    set_base_dir (Direction direction) -> void;

    auto
    get_base_dir () const -> Direction;

    auto
    set_base_gravity (Gravity gravity) -> void;

    auto
    get_base_gravity () const -> Gravity;

    auto
    get_gravity () const -> Gravity;

    auto
    set_gravity_hint (GravityHint hint) -> void;

    auto
    get_gravity_hint () const -> GravityHint;

    auto
    set_matrix (const Matrix& matrix) -> void;

    auto
    get_matrix () const -> Matrix;

    auto
    itemize (const glib::ustring& text, const AttrList& attrs) const
        -> std::vector<Item>;

    auto
    itemize (const glib::ustring& text,
             int start_index,
             int length,
             const AttrList& attrs,
             AttrIter& cached_iter) const -> std::vector<Item>;

    auto
    update_from_cairo_context (const cairo::RefPtr<cairo::Context>& context)
        -> void;

    auto
    set_cairo_font_options (const cairo::FontOptions& options) -> void;

    auto
    get_font_options () const -> cairo::FontOptions;

    auto
    set_resolution (double dpi) -> void;

    auto
    get_resolution () const -> double;

  public:
  public:
  protected:
  };

} // namespace pango

namespace glib
{

  LIBMM_PANGO_SYMEXPORT
  auto
  wrap (PangoContext* object, bool take_copy = false) -> glib::RefPtr<pango::Context>;
} // namespace glib

#endif
