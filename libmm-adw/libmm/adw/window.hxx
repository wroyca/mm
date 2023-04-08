// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_WINDOW_H
#define _LIBADWAITAMM_WINDOW_H

#include <libmm/adw/mm-adwconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/mm-gtk.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using AdwWindow = struct _AdwWindow;
using AdwWindowClass = struct _AdwWindowClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace adw
{
  class LIBMM_ADW_SYMEXPORT window_class;
}
#endif

namespace adw
{

  class LIBMM_ADW_SYMEXPORT window : public gtk::Window
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = window;
    using CppClassType = window_class;
    using BaseObjectType = AdwWindow;
    using BaseClassType = AdwWindowClass;
#endif

    window (window&& src) noexcept;
    auto
    operator= (window&& src) noexcept -> window&;

    window (const window&) = delete;
    auto
    operator= (const window&) -> window& = delete;

    ~window () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend class window_class;
    static CppClassType window_class_;

  protected:
    explicit window (const glib::ConstructParams& construct_params);
    explicit window (AdwWindow* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> AdwWindow*
    {
      return reinterpret_cast<AdwWindow*> (gobject_);
    }

    auto
    gobj () const -> const AdwWindow*
    {
      return reinterpret_cast<AdwWindow*> (gobject_);
    }

  private:
  public:
    window ();

    auto
    get_content () const -> gtk::Widget*;

    auto
    set_content (gtk::Widget* content) -> void;

    auto
    property_content () -> glib::PropertyProxy<gtk::Widget*>;

    auto
    property_content () const -> glib::PropertyProxy_ReadOnly<gtk::Widget*>;

  public:
  public:
  protected:
  };

} // namespace adw

namespace glib
{

  auto
  wrap (AdwWindow* object, bool take_copy = false) -> adw::window*;
}

#endif
