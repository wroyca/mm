// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_STYLEPROVIDER_H
#define _GTKMM_STYLEPROVIDER_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gdk/display.hxx>
#include <libmm/glib/interface.hxx>
#include <libmm/gtk/enums.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _GtkStyleProviderIface GtkStyleProviderIface;
}
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkStyleProvider = struct _GtkStyleProvider;
using GtkStyleProviderClass = struct _GtkStyleProviderClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT StyleProvider_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT StyleProvider : public glib::Interface
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = StyleProvider;
    using CppClassType = StyleProvider_Class;
    using BaseObjectType = GtkStyleProvider;
    using BaseClassType = GtkStyleProviderIface;

    StyleProvider (const StyleProvider&) = delete;
    auto
    operator= (const StyleProvider&) -> StyleProvider& = delete;

  private:
    friend class StyleProvider_Class;
    static CppClassType styleprovider_class_;

#endif
  protected:
    StyleProvider ();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    explicit StyleProvider (const glib::Interface_Class& interface_class);

  public:
    explicit StyleProvider (GtkStyleProvider* castitem);

  protected:
#endif

  public:
    StyleProvider (StyleProvider&& src) noexcept;
    auto
    operator= (StyleProvider&& src) noexcept -> StyleProvider&;

    ~StyleProvider () noexcept override;

    static auto
    add_interface (GType gtype_implementer) -> void;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkStyleProvider*
    {
      return reinterpret_cast<GtkStyleProvider*> (gobject_);
    }

    auto
    gobj () const -> const GtkStyleProvider*
    {
      return reinterpret_cast<GtkStyleProvider*> (gobject_);
    }

  private:
  public:
    static auto
    add_provider_for_display (const glib::RefPtr<gdk::Display>& display,
                              const glib::RefPtr<StyleProvider>& provider,
                              guint priority) -> void;

    static auto
    remove_provider_for_display (const glib::RefPtr<gdk::Display>& display,
                                 const glib::RefPtr<StyleProvider>& provider)
        -> void;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkStyleProvider* object, bool take_copy = false) -> glib::RefPtr<gtk::StyleProvider>;

} // namespace glib

#endif
