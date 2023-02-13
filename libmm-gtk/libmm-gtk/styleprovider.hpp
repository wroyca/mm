
#ifndef _GTKMM_STYLEPROVIDER_H
#define _GTKMM_STYLEPROVIDER_H


#include <libmm-glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2010 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <libmm-glib/interface.hpp>
#include <libmm-gtk/enums.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
typedef struct _GtkStyleProviderIface GtkStyleProviderIface;
}
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkStyleProvider = struct _GtkStyleProvider;
using GtkStyleProviderClass = struct _GtkStyleProviderClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API StyleProvider_Class; } // namespace Gtk
#endif // DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** Interface to provide style information to Gtk::StyleContext.
 *
 * %Gtk::StyleProvider is an interface used to provide style information to a Gtk::StyleContext.
 * See StyleContext::add_provider() and StyleContext::add_provider_for_display().
 *
 * @see Gtk::StyleContext, Gtk::CssProvider

 * @newin{3,0}
 */

class GTKMM_API StyleProvider : public Glib::Interface
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = StyleProvider;
  using CppClassType = StyleProvider_Class;
  using BaseObjectType = GtkStyleProvider;
  using BaseClassType = GtkStyleProviderIface;

  // noncopyable
  StyleProvider(const StyleProvider&) = delete;
  auto operator=(const StyleProvider&) -> StyleProvider& = delete;

private:
  friend class StyleProvider_Class;
  static CppClassType styleprovider_class_;

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
protected:
  /**
   * You should derive from this class to use it.
   */
  StyleProvider();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  /** Called by constructors of derived classes. Provide the result of
   * the Class init() function to ensure that it is properly
   * initialized.
   *
   * @param interface_class The Class object for the derived type.
   */
  explicit StyleProvider(const Glib::Interface_Class& interface_class);

public:
  // This is public so that C++ wrapper instances can be
  // created for C instances of unwrapped types.
  // For instance, if an unexpected C type implements the C interface.
  explicit StyleProvider(GtkStyleProvider* castitem);

protected:
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  StyleProvider(StyleProvider&& src) noexcept;
  auto operator=(StyleProvider&& src) noexcept -> StyleProvider&;

  ~StyleProvider() noexcept override;

  static void add_interface(GType gtype_implementer);

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkStyleProvider*       { return reinterpret_cast<GtkStyleProvider*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkStyleProvider* { return reinterpret_cast<GtkStyleProvider*>(gobject_); }

private:


public:
  // There is no public API.


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} // namespace Gtk


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::StyleProvider
   */
  GTKMM_API
  auto wrap(GtkStyleProvider* object, bool take_copy = false) -> Glib::RefPtr<Gtk::StyleProvider>;

} // namespace Glib


#endif /* _GTKMM_STYLEPROVIDER_H */

