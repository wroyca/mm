
#ifndef _GIOMM_LOADABLEICON_H
#define _GIOMM_LOADABLEICON_H


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/* Copyright (C) 2007 The giomm Development Team
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
 * License along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <libmm-glib/interface.hxx>
#include <libmm-gio/inputstream.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GLoadableIconIface GLoadableIconIface;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GLoadableIcon = struct _GLoadableIcon;
using GLoadableIconClass = struct _GLoadableIconClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API LoadableIcon_Class; } // namespace Gio
#endif // DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

/** Extends the Icon interface and adds the ability to load icons from streams.
 *
 * @newin{2,16}
 */

class GIOMM_API LoadableIcon : public Glib::Interface
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = LoadableIcon;
  using CppClassType = LoadableIcon_Class;
  using BaseObjectType = GLoadableIcon;
  using BaseClassType = GLoadableIconIface;

  // noncopyable
  LoadableIcon(const LoadableIcon&) = delete;
  auto operator=(const LoadableIcon&) -> LoadableIcon& = delete;

private:
  friend class LoadableIcon_Class;
  static CppClassType loadableicon_class_;

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
protected:
  /**
   * You should derive from this class to use it.
   */
  LoadableIcon();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  /** Called by constructors of derived classes. Provide the result of
   * the Class init() function to ensure that it is properly
   * initialized.
   *
   * @param interface_class The Class object for the derived type.
   */
  explicit LoadableIcon(const Glib::Interface_Class& interface_class);

public:
  // This is public so that C++ wrapper instances can be
  // created for C instances of unwrapped types.
  // For instance, if an unexpected C type implements the C interface.
  explicit LoadableIcon(GLoadableIcon* castitem);

protected:
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  LoadableIcon(LoadableIcon&& src) noexcept;
  auto operator=(LoadableIcon&& src) noexcept -> LoadableIcon&;

  ~LoadableIcon() noexcept override;

  static void add_interface(GType gtype_implementer);

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GLoadableIcon*       { return reinterpret_cast<GLoadableIcon*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GLoadableIcon* { return reinterpret_cast<GLoadableIcon*>(gobject_); }

private:


public:
/**
 * Loads a loadable icon. For the asynchronous version of this function,
 * see load_async().
 *
 * @param size an integer.
 * @param type a location to store the type of the loaded icon
 * @param cancellable a Cancellable object
 *
 * @return a InputStream to read the icon from.
 **/
  auto load(int size, Glib::ustring& type, const Glib::RefPtr<Cancellable>& cancellable) -> Glib::RefPtr<InputStream>;
  /** Non-cancellable version of load()
   */
  auto load(int size, Glib::ustring& type) -> Glib::RefPtr<InputStream>;
  //TODO: 'type' can be nullptr as well, but I don't really want to add 2 more
  //overloads -- one cancellable, and one not...

  /**
   * Loads an icon asynchronously. To finish this function, see load_finish().
   * For the synchronous, blocking version of this function, see load().
   *
   * @param size an integer.
   * @param cancellable a Cancellable object
   * @param slot a function to call when the request is satisfied
   **/
  void load_async(int size, const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable);
  /** Non-cancellable version of load_async()
   */
  void load_async(int size, const SlotAsyncReady& slot);
  //_WRAP_METHOD(Glib::RefPtr<InputStream> load_finish(const Glib::RefPtr<AsyncResult>& res, Glib::ustring& type), g_loadable_icon_load_finish, errthrow)

protected:
  //_WRAP_VFUNC(Glib::RefPtr<InputStream> load(int size, Glib::ustring& type, const Glib::RefPtr<Cancellable>& cancellable), "load")


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};


} // namespace Gio


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gio::LoadableIcon
   */
  GIOMM_API
  auto wrap(GLoadableIcon* object, bool take_copy = false) -> Glib::RefPtr<Gio::LoadableIcon>;

} // namespace Glib


#endif /* _GIOMM_LOADABLEICON_H */

