// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_BINLAYOUT_H
#define _GTKMM_BINLAYOUT_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/layoutmanager.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT BinLayout_Class;
}
#endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT BinLayout : public LayoutManager
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = BinLayout;
    using CppClassType = BinLayout_Class;
    using BaseObjectType = GtkBinLayout;
    using BaseClassType = GtkBinLayoutClass;

    BinLayout (const BinLayout&) = delete;
    auto
    operator= (const BinLayout&) -> BinLayout& = delete;

  private:
    friend class BinLayout_Class;
    static CppClassType binlayout_class_;

  protected:
    explicit BinLayout (const Glib::ConstructParams& construct_params);
    explicit BinLayout (GtkBinLayout* castitem);

#endif

  public:
    BinLayout (BinLayout&& src) noexcept;
    auto
    operator= (BinLayout&& src) noexcept -> BinLayout&;

    ~BinLayout () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkBinLayout*
    {
      return reinterpret_cast<GtkBinLayout*> (gobject_);
    }

    auto
    gobj () const -> const GtkBinLayout*
    {
      return reinterpret_cast<GtkBinLayout*> (gobject_);
    }

    auto
    gobj_copy () -> GtkBinLayout*;

  private:
  protected:
    BinLayout ();

  public:
    static auto
    create () -> Glib::RefPtr<BinLayout>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkBinLayout* object, bool take_copy = false) -> Glib::RefPtr<Gtk::BinLayout>;
} // namespace Glib

#endif
