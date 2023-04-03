// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_BIN_H
#define _LIBADWAITAMM_BIN_H

#include <libmm/adw/mm-adwconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/mm-gtk.hxx>

#include <adwaita.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Adw
{
  class LIBMM_ADW_SYMEXPORT Bin_Class;
}
#endif

namespace Adw
{

  class LIBMM_ADW_SYMEXPORT Bin : public Gtk::Widget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef Bin CppObjectType;
    typedef Bin_Class CppClassType;
    typedef AdwBin BaseObjectType;
    typedef AdwBinClass BaseClassType;
#endif

    Bin (Bin&& src) noexcept;
    auto
    operator= (Bin&& src) noexcept -> Bin&;

    Bin (const Bin&) = delete;
    auto
    operator= (const Bin&) -> Bin& = delete;

    ~Bin () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend class Bin_Class;
    static CppClassType bin_class_;

  protected:
    explicit Bin (const Glib::ConstructParams& construct_params);
    explicit Bin (AdwBin* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> AdwBin*
    {
      return reinterpret_cast<AdwBin*> (gobject_);
    }

    auto
    gobj () const -> const AdwBin*
    {
      return reinterpret_cast<AdwBin*> (gobject_);
    }

  private:
  public:
    Bin ();

    auto
    get_child () const -> Gtk::Widget*;

    auto
    set_child (Gtk::Widget* widget) -> void;

    auto
    property_child () -> Glib::PropertyProxy<Gtk::Widget*>;

    auto
    property_child () const -> Glib::PropertyProxy_ReadOnly<Gtk::Widget*>;

  public:
  public:
  protected:
  };

} // namespace Adw

namespace Glib
{

  auto
  wrap (AdwBin* object, bool take_copy = false) -> Adw::Bin*;
}

#endif
