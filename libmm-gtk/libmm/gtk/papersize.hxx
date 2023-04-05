// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_PAPERSIZE_H
#define _GTKMM_PAPERSIZE_H

#include <libmm/gtk/mm-gtkconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/glib/keyfile.hxx>
#include <libmm/glib/value.hxx>
#include <vector>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _GtkPaperSize GtkPaperSize;
}
#endif

namespace gtk
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  struct PaperSizeTraits;
#endif

  extern LIBMM_GTK_SYMEXPORT const glib::ustring PAPER_NAME_A3;
  extern LIBMM_GTK_SYMEXPORT const glib::ustring PAPER_NAME_A4;
  extern LIBMM_GTK_SYMEXPORT const glib::ustring PAPER_NAME_A5;
  extern LIBMM_GTK_SYMEXPORT const glib::ustring PAPER_NAME_B5;
  extern LIBMM_GTK_SYMEXPORT const glib::ustring PAPER_NAME_LETTER;
  extern LIBMM_GTK_SYMEXPORT const glib::ustring PAPER_NAME_EXECUTIVE;
  extern LIBMM_GTK_SYMEXPORT const glib::ustring PAPER_NAME_LEGAL;

  enum class Unit
  {
    NONE,
    POINTS,
    INCH,
    MM
  };

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::Unit> : public glib::Value_Enum<gtk::Unit>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT PaperSize
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = PaperSize;
    using BaseObjectType = GtkPaperSize;
#endif

    static auto
    get_type () -> GType G_GNUC_CONST;

    PaperSize ();

    explicit PaperSize (GtkPaperSize* gobject, bool make_a_copy = true);

    PaperSize (const PaperSize& other);
    auto
    operator= (const PaperSize& other) -> PaperSize&;

    PaperSize (PaperSize&& other) noexcept;
    auto
    operator= (PaperSize&& other) noexcept -> PaperSize&;

    ~PaperSize () noexcept;

    auto
    swap (PaperSize& other) noexcept -> void;

    auto
    gobj () -> GtkPaperSize*
    {
      return gobject_;
    }

    auto
    gobj () const -> const GtkPaperSize*
    {
      return gobject_;
    }

    auto
    gobj_copy () const -> GtkPaperSize*;

  protected:
    GtkPaperSize* gobject_;

  private:
  public:
    explicit PaperSize (const glib::ustring& name);
    explicit PaperSize (const glib::ustring& ppd_name,
                        const glib::ustring& ppd_display_name,
                        double width,
                        double height);
    explicit PaperSize (const glib::ustring& name,
                        const glib::ustring& display_name,
                        double width,
                        double height,
                        Unit unit);

    explicit PaperSize (const glib::RefPtr<const glib::KeyFile>& key_file,
                        const glib::ustring& group_name = {});

    auto
    equal (const PaperSize& other) const -> bool;

    explicit operator bool () const;

    static auto
    get_paper_sizes (bool include_custom = true) -> std::vector<PaperSize>;

    auto
    get_name () const -> glib::ustring;

    auto
    get_display_name () const -> glib::ustring;

    auto
    get_ppd_name () const -> glib::ustring;

    auto
    get_width (Unit unit) const -> double;

    auto
    get_height (Unit unit) const -> double;

    auto
    is_custom () const -> bool;

    auto
    is_ipp () const -> bool;

    auto
    set_size (double width, double height, Unit unit) -> void;

    auto
    get_default_top_margin (Unit unit) const -> double;

    auto
    get_default_bottom_margin (Unit unit) const -> double;

    auto
    get_default_left_margin (Unit unit) const -> double;

    auto
    get_default_right_margin (Unit unit) const -> double;

    static auto
    get_default () -> glib::ustring;

    auto
    save_to_key_file (const glib::RefPtr<glib::KeyFile>& key_file,
                      const glib::ustring& group_name) -> void;

    auto
    save_to_key_file (const glib::RefPtr<glib::KeyFile>& key_file) -> void;
  };

  inline auto
  operator== (const PaperSize& lhs, const PaperSize& rhs) -> bool
  {
    return lhs.equal (rhs);
  }

  inline auto
  operator!= (const PaperSize& lhs, const PaperSize& rhs) -> bool
  {
    return !lhs.equal (rhs);
  }

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  struct PaperSizeTraits
  {
    typedef PaperSize CppType;
    typedef const GtkPaperSize* CType;
    typedef GtkPaperSize* CTypeNonConst;

    static auto
    to_c_type (const CppType& obj) -> CType
    {
      return obj.gobj ();
    }

    static auto
    to_c_type (CType ptr) -> CType
    {
      return ptr;
    }

    static auto
    to_cpp_type (CType ptr) -> CppType
    {
      return PaperSize (const_cast<GtkPaperSize*> (ptr), true);
    }

    static auto
    release_c_type (CType ptr) -> void;
  };
#endif

} // namespace gtk

namespace gtk
{

  inline auto
  swap (PaperSize& lhs, PaperSize& rhs) noexcept -> void
  {
    lhs.swap (rhs);
  }

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkPaperSize* object, bool take_copy = false) -> gtk::PaperSize;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::PaperSize>
    : public glib::Value_Boxed<gtk::PaperSize>
  {
  };
#endif

} // namespace glib

#endif
