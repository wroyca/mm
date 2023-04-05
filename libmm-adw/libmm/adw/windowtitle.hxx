// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_WINDOWTITLE_H
#define _LIBADWAITAMM_WINDOWTITLE_H

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
  class LIBMM_ADW_SYMEXPORT WindowTitle_Class;
}
#endif

namespace adw
{

  class LIBMM_ADW_SYMEXPORT WindowTitle : public gtk::Widget
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
    explicit WindowTitle (const glib::ConstructParams& construct_params);
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
    explicit WindowTitle (const glib::ustring& title,
                          const glib::ustring& subtitle);

    auto
    get_subtitle () const -> glib::ustring;

    auto
    get_title () const -> glib::ustring;

    auto
    set_subtitle (const glib::ustring& str) -> void;

    auto
    set_title (const glib::ustring& str) -> void;

    auto
    property_title () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_title () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_subtitle () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_subtitle () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

  public:
  public:
  protected:
  };

} // namespace adw

namespace glib
{

  auto
  wrap (AdwWindowTitle* object, bool take_copy = false) -> adw::WindowTitle*;
}

#endif
