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
namespace adw
{
  class LIBMM_ADW_SYMEXPORT bin_class;
}
#endif

namespace adw
{

  class LIBMM_ADW_SYMEXPORT bin : public gtk::Widget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = bin;
    using CppClassType = bin_class;
    using BaseObjectType = AdwBin;
    using BaseClassType = AdwBinClass;
#endif

    bin (bin&& src) noexcept;
    auto
    operator= (bin&& src) noexcept -> bin&;

    bin (const bin&) = delete;
    auto
    operator= (const bin&) -> bin& = delete;

    ~bin () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend class bin_class;
    static CppClassType bin_class_;

  protected:
    explicit bin (const glib::ConstructParams& construct_params);
    explicit bin (AdwBin* castitem);

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
    bin ();

    auto
    get_child () const -> gtk::Widget*;

    auto
    set_child (gtk::Widget* widget) -> void;

    auto
    property_child () -> glib::PropertyProxy<gtk::Widget*>;

    auto
    property_child () const -> glib::PropertyProxy_ReadOnly<gtk::Widget*>;

  public:
  public:
  protected:
  };

} // namespace adw

namespace glib
{

  auto
  wrap (AdwBin* object, bool take_copy = false) -> adw::bin*;
}

#endif
