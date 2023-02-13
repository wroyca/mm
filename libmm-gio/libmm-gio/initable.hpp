
#ifndef _GIOMM_INITABLE_H
#define _GIOMM_INITABLE_H


#include <mm/glib/ustring.hpp>
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

#include <mm/glib/interface.hpp>
#include <mm/gio/cancellable.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GInitableIface GInitableIface;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GInitable = struct _GInitable;
using GInitableClass = struct _GInitableClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API Initable_Class; } // namespace Gio
#endif // DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

/** Failable object initialization interface
 *
 * Initable is implemented by objects that can fail during initialization. If
 * an object implements this interface the init() function must be called as the
 * first thing after construction. If init() is not called, or if it returns an
 * error, all further operations on the object should fail, generally with a
 * G_IO_ERROR_NOT_INITIALIZED error.
 *
 * Users of objects implementing this are not intended to use the interface
 * method directly, instead it will be used automatically in various ways. For C
 * applications you generally just call g_initable_new() directly, or indirectly
 * via a foo_thing_new() wrapper. This will call g_initable_init() under the
 * cover, returning nullptr and setting a GError on failure.
 *
 * For bindings in languages where the native constructor supports exceptions
 * the binding could check for objects implemention GInitable during normal
 * construction and automatically initialize them, throwing an exception on
 * failure.
 *
 * @newin{2,24}
 */

class GIOMM_API Initable : public Glib::Interface
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = Initable;
  using CppClassType = Initable_Class;
  using BaseObjectType = GInitable;
  using BaseClassType = GInitableIface;

  // noncopyable
  Initable(const Initable&) = delete;
  auto operator=(const Initable&) -> Initable& = delete;

private:
  friend class Initable_Class;
  static CppClassType initable_class_;

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
protected:
  /**
   * You should derive from this class to use it.
   */
  Initable();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  /** Called by constructors of derived classes. Provide the result of
   * the Class init() function to ensure that it is properly
   * initialized.
   *
   * @param interface_class The Class object for the derived type.
   */
  explicit Initable(const Glib::Interface_Class& interface_class);

public:
  // This is public so that C++ wrapper instances can be
  // created for C instances of unwrapped types.
  // For instance, if an unexpected C type implements the C interface.
  explicit Initable(GInitable* castitem);

protected:
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  Initable(Initable&& src) noexcept;
  auto operator=(Initable&& src) noexcept -> Initable&;

  ~Initable() noexcept override;

  static void add_interface(GType gtype_implementer);

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GInitable*       { return reinterpret_cast<GInitable*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GInitable* { return reinterpret_cast<GInitable*>(gobject_); }

private:


protected:

  /** Initializes the object implementing the interface.
   *
   * This method is intended for language bindings. If writing in C,
   * g_initable_new() should typically be used instead.
   *
   * The object must be initialized before any real use after initial
   * construction, either with this function or g_async_initable_init_async().
   *
   * Implementations may also support cancellation. If @a cancellable is not <tt>nullptr</tt>,
   * then initialization can be cancelled by triggering the cancellable object
   * from another thread. If the operation was cancelled, the error
   * Gio::Error::CANCELLED will be returned. If @a cancellable is not <tt>nullptr</tt> and
   * the object doesn't support cancellable initialization the error
   * Gio::Error::NOT_SUPPORTED will be returned.
   *
   * If the object is not initialized, or initialization returns with an
   * error, then all operations on the object except Glib::object_ref() and
   * Glib::object_unref() are considered to be invalid, and have undefined
   * behaviour. See the [introduction][ginitable] for more details.
   *
   * Callers should not assume that a class which implements Initable can be
   * initialized multiple times, unless the class explicitly documents itself as
   * supporting this. Generally, a class’ implementation of init() can assume
   * (and assert) that it will only be called once. Previously, this documentation
   * recommended all Initable implementations should be idempotent; that
   * recommendation was relaxed in GLib 2.54.
   *
   * If a class explicitly supports being initialized multiple times, it is
   * recommended that the method is idempotent: multiple calls with the same
   * arguments should return the same results. Only the first call initializes
   * the object; further calls return the result of the first call.
   *
   * One reason why a class might need to support idempotent initialization is if
   * it is designed to be used via the singleton pattern, with a
   * ObjectClass.constructor that sometimes returns an existing instance.
   * In this pattern, a caller would expect to be able to call g_initable_init()
   * on the result of Glib::object_new(), regardless of whether it is in fact a new
   * instance.
   *
   * @newin{2,22}
   *
   * @param cancellable Optional Cancellable object, <tt>nullptr</tt> to ignore.
   *
   * @throws Glib::Error
   */
  void init(const Glib::RefPtr<Cancellable>& cancellable);

  /// A init() convenience overload.
  void init();

protected:
    virtual auto init_vfunc(const Glib::RefPtr<Cancellable>& cancellable, GError** error) -> bool;


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
   * @relates Gio::Initable
   */
  GIOMM_API
  auto wrap(GInitable* object, bool take_copy = false) -> Glib::RefPtr<Gio::Initable>;

} // namespace Glib


#endif /* _GIOMM_INITABLE_H */

