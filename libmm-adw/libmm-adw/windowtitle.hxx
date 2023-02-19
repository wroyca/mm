// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_WINDOWTITLE_H
#define _LIBADWAITAMM_WINDOWTITLE_H

#include <libmm-adw/mm-adwconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/mm-gtk.hxx>

#include <adwaita.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Adw
{
  class LIBMM_ADW_SYMEXPORT WindowTitle_Class;
}
#endif

namespace Adw
{

  class LIBMM_ADW_SYMEXPORT WindowTitle : public Gtk::Widget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef WindowTitle CppObjectType;
    typedef WindowTitle_Class CppClassType;
    typedef AdwWindowTitle BaseObjectType;
    typedef AdwWindowTitleClass BaseClassType;
#endif

    WindowTitle (WindowTitle&& src) noexcept;
    auto
    operator= (WindowTitle&& src) noexcept -> WindowTitle&;

    WindowTitle (const WindowTitle&) = delete;
    auto
    operator= (const WindowTitle&) -> WindowTitle& = delete;

    ~WindowTitle () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend class WindowTitle_Class;
    static CppClassType windowtitle_class_;

  protected:
    explicit WindowTitle (const Glib::ConstructParams& construct_params);
    explicit WindowTitle (AdwWindowTitle* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> AdwWindowTitle*
    {
      return reinterpret_cast<AdwWindowTitle*> (gobject_);
    }

    auto
    gobj () const -> const AdwWindowTitle*
    {
      return reinterpret_cast<AdwWindowTitle*> (gobject_);
    }

  private:
  public:
    WindowTitle ();
    explicit WindowTitle (const Glib::ustring& title,
                          const Glib::ustring& subtitle);

    auto
    get_subtitle () const -> Glib::ustring;

    auto
    get_title () const -> Glib::ustring;

    auto
    set_subtitle (const Glib::ustring& str) -> void;

    auto
    set_title (const Glib::ustring& str) -> void;

    auto
    property_title () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_title () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_subtitle () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_subtitle () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

  public:
  public:
  protected:
  };

} // namespace Adw

namespace Glib
{

  auto
  wrap (AdwWindowTitle* object, bool take_copy = false) -> Adw::WindowTitle*;
}

#endif
