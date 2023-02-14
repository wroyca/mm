
#ifndef _PANGOMM_CONTEXT_H
#define _PANGOMM_CONTEXT_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-cairo/context.hxx>
#include <libmm-cairo/fontoptions.hxx>
#include <libmm-glib/object.hxx>
#include <libmm-pango/attrlist.hxx>
#include <libmm-pango/fontdescription.hxx>
#include <libmm-pango/fontmap.hxx>
#include <libmm-pango/fontmetrics.hxx>
#include <libmm-pango/fontset.hxx>
#include <libmm-pango/item.hxx>
#include <libmm-pango/types.hxx>
#include <pango/pango.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using PangoContext = struct _PangoContext;
using PangoContextClass = struct _PangoContextClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Pango
{
  class PANGOMM_API Context_Class;
}
#endif

namespace Pango
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

} // namespace Pango

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class PANGOMM_API Value<Pango::Direction>
    : public Glib::Value_Enum<Pango::Direction>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Pango
{

  enum class GravityHint
  {
    NATURAL,
    STRONG,
    LINE
  };

} // namespace Pango

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class PANGOMM_API Value<Pango::GravityHint>
    : public Glib::Value_Enum<Pango::GravityHint>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Pango
{

  class PANGOMM_API Context : public Glib::Object
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
    explicit Context (const Glib::ConstructParams& construct_params);
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
    list_families () const -> std::vector<Glib::RefPtr<FontFamily>>;

    void
    set_font_map (const Glib::RefPtr<FontMap>& font_map);

    auto
    get_font_map () -> Glib::RefPtr<FontMap>;

    auto
    get_font_map () const -> Glib::RefPtr<const FontMap>;

    auto
    get_serial () const -> guint;

    auto
    load_font (const FontDescription& desc) const -> Glib::RefPtr<Font>;

    auto
    load_fontset (const FontDescription& desc, const Language& language) const
        -> Glib::RefPtr<Fontset>;

    auto
    get_metrics (const FontDescription& desc) const -> FontMetrics;

    auto
    get_metrics (const FontDescription& desc, const Language& language) const
        -> FontMetrics;

    void
    set_font_description (const FontDescription& desc);

    auto
    get_font_description () const -> FontDescription;

    auto
    get_language () const -> Language;

    void
    set_language (const Language& language);

    void
    set_base_dir (Direction direction);

    auto
    get_base_dir () const -> Direction;

    void
    set_base_gravity (Gravity gravity);

    auto
    get_base_gravity () const -> Gravity;

    auto
    get_gravity () const -> Gravity;

    void
    set_gravity_hint (GravityHint hint);

    auto
    get_gravity_hint () const -> GravityHint;

    void
    set_matrix (const Matrix& matrix);

    auto
    get_matrix () const -> Matrix;

    auto
    itemize (const Glib::ustring& text, const AttrList& attrs) const
        -> std::vector<Item>;

    auto
    itemize (const Glib::ustring& text,
             int start_index,
             int length,
             const AttrList& attrs,
             AttrIter& cached_iter) const -> std::vector<Item>;

    void
    update_from_cairo_context (const Cairo::RefPtr<Cairo::Context>& context);

    void
    set_cairo_font_options (const Cairo::FontOptions& options);

    auto
    get_font_options () const -> Cairo::FontOptions;

    void
    set_resolution (double dpi);

    auto
    get_resolution () const -> double;

  public:
  public:
  protected:
  };

} // namespace Pango

namespace Glib
{

  PANGOMM_API
  auto
  wrap (PangoContext* object, bool take_copy = false) -> Glib::RefPtr<Pango::Context>;
} // namespace Glib

#endif
