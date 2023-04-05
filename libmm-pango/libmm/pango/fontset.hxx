// SPDX-License-Identifier: LGPL-2.0-or-later

#ifndef _PANGOMM_FONTSET_H
#define _PANGOMM_FONTSET_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/glib/object.hxx>
#include <libmm/pango/font.hxx>
#include <libmm/pango/fontmetrics.hxx>
#include <libmm/pango/language.hxx>
#include <pango/pango.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using PangoFontset = struct _PangoFontset;
using PangoFontsetClass = struct _PangoFontsetClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace pango
{
  class LIBMM_PANGO_SYMEXPORT Fontset_Class;
}
#endif

namespace pango
{

  class LIBMM_PANGO_SYMEXPORT Fontset : public glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Fontset;
    using CppClassType = Fontset_Class;
    using BaseObjectType = PangoFontset;
    using BaseClassType = PangoFontsetClass;

    Fontset (const Fontset&) = delete;
    auto
    operator= (const Fontset&) -> Fontset& = delete;

  private:
    friend class Fontset_Class;
    static CppClassType fontset_class_;

  protected:
    explicit Fontset (const glib::ConstructParams& construct_params);
    explicit Fontset (PangoFontset* castitem);

#endif

  public:
    Fontset (Fontset&& src) noexcept;
    auto
    operator= (Fontset&& src) noexcept -> Fontset&;

    ~Fontset () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> PangoFontset*
    {
      return reinterpret_cast<PangoFontset*> (gobject_);
    }

    auto
    gobj () const -> const PangoFontset*
    {
      return reinterpret_cast<PangoFontset*> (gobject_);
    }

    auto
    gobj_copy () -> PangoFontset*;

  private:
  public:
    auto
    get_font (guint wc) const -> glib::RefPtr<Font>;

    auto
    get_metrics () const -> FontMetrics;

    typedef sigc::slot<bool (const glib::RefPtr<Font>&)> ForeachSlot;

    auto foreach (const ForeachSlot& slot) -> void;

  public:
  public:
  protected:
  };

} // namespace pango

namespace glib
{

  LIBMM_PANGO_SYMEXPORT
  auto
  wrap (PangoFontset* object, bool take_copy = false) -> glib::RefPtr<pango::Fontset>;
} // namespace glib

#endif
