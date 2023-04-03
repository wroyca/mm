// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_PAGESETUP_H
#define _GTKMM_PAGESETUP_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/glib/object.hxx>
#include <libmm/gtk/enums.hxx>
#include <libmm/gtk/papersize.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkPageSetup = struct _GtkPageSetup;
using GtkPageSetupClass = struct _GtkPageSetupClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT PageSetup_Class;
}
#endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT PageSetup : public Glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = PageSetup;
    using CppClassType = PageSetup_Class;
    using BaseObjectType = GtkPageSetup;
    using BaseClassType = GtkPageSetupClass;

    PageSetup (const PageSetup&) = delete;
    auto
    operator= (const PageSetup&) -> PageSetup& = delete;

  private:
    friend class PageSetup_Class;
    static CppClassType pagesetup_class_;

  protected:
    explicit PageSetup (const Glib::ConstructParams& construct_params);
    explicit PageSetup (GtkPageSetup* castitem);

#endif

  public:
    PageSetup (PageSetup&& src) noexcept;
    auto
    operator= (PageSetup&& src) noexcept -> PageSetup&;

    ~PageSetup () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkPageSetup*
    {
      return reinterpret_cast<GtkPageSetup*> (gobject_);
    }

    auto
    gobj () const -> const GtkPageSetup*
    {
      return reinterpret_cast<GtkPageSetup*> (gobject_);
    }

    auto
    gobj_copy () -> GtkPageSetup*;

  private:
  protected:
    PageSetup ();

  public:
    static auto
    create () -> Glib::RefPtr<PageSetup>;

    static auto
    create_from_key_file (const Glib::RefPtr<const Glib::KeyFile>& key_file)
        -> Glib::RefPtr<PageSetup>;

    static auto
    create_from_key_file (const Glib::RefPtr<const Glib::KeyFile>& key_file,
                          const Glib::ustring& group_name)
        -> Glib::RefPtr<PageSetup>;

    static auto
    create_from_file (const std::string& file_name) -> Glib::RefPtr<PageSetup>;

    auto
    copy () const -> Glib::RefPtr<PageSetup>;

    auto
    load_from_file (const std::string& file_name) -> bool;

    auto
    load_from_key_file (const Glib::RefPtr<const Glib::KeyFile>& key_file,
                        const Glib::ustring& group_name) -> bool;

    auto
    load_from_key_file (const Glib::RefPtr<const Glib::KeyFile>& key_file)
        -> bool;

    auto
    get_orientation () const -> PageOrientation;

    auto
    set_orientation (PageOrientation orientation) -> void;

    auto
    get_paper_size () -> PaperSize;

    auto
    get_paper_size () const -> const PaperSize;

    auto
    set_paper_size (const PaperSize& size) -> void;

    auto
    get_top_margin (Unit unit) const -> double;

    auto
    set_top_margin (double margin, Unit unit) -> void;

    auto
    get_bottom_margin (Unit unit) const -> double;

    auto
    set_bottom_margin (double margin, Unit unit) -> void;

    auto
    get_left_margin (Unit unit) const -> double;

    auto
    set_left_margin (double margin, Unit unit) -> void;

    auto
    get_right_margin (Unit unit) const -> double;

    auto
    set_right_margin (double margin, Unit unit) -> void;

    auto
    set_paper_size_and_default_margins (const PaperSize& size) -> void;

    auto
    get_paper_width (Unit unit) const -> double;

    auto
    get_paper_height (Unit unit) const -> double;

    auto
    get_page_width (Unit unit) const -> double;

    auto
    get_page_height (Unit unit) const -> double;

    auto
    save_to_file (const std::string& file_name) const -> bool;

    auto
    save_to_key_file (const Glib::RefPtr<Glib::KeyFile>& key_file,
                      const Glib::ustring& group_name) const -> void;

    auto
    save_to_key_file (const Glib::RefPtr<Glib::KeyFile>& key_file) const
        -> void;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkPageSetup* object, bool take_copy = false) -> Glib::RefPtr<Gtk::PageSetup>;
} // namespace Glib

#endif
