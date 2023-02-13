
#ifndef _GIOMM_ASYNCRESULT_H
#define _GIOMM_ASYNCRESULT_H

#include <libmm-gio/gioconfig.hxx>


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
#include <libmm-glib/object.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GAsyncResultIface GAsyncResultIface;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GAsyncResult = struct _GAsyncResult;
using GAsyncResultClass = struct _GAsyncResultClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API AsyncResult_Class; } // namespace Gio
#endif // DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

class GIOMM_API AsyncResult;

/** A function that will be called when an asynchronous operation within GIO has been completed.
 * @param result The asynchronous function's results.
 *
 * For instance,
 * @code
 * void on_async_ready(Glib::RefPtr<Gio::AsyncResult>& result);
 * @endcode
 *
 * @newin{2,16}
 * @relates Gio::AsyncResult
 */
using SlotAsyncReady = sigc::slot<void(Glib::RefPtr<AsyncResult>&)>;

/** Provides a base class for implementing asynchronous function results.
 *
 * Asynchronous operations are broken up into two separate operations which are chained together by a SlotAsyncReady.
 * To begin an asynchronous operation, provide a SlotAsyncReady to the asynchronous function. This callback will be triggered
 * when the operation has completed, and will be passed an %AsyncResult instance
 * (an instance of a class that implements the %AsyncResult interface)
 * filled with the details of the operation's success or failure,
 * the object the asynchronous function was started for and any error codes returned. The asynchronous callback function is then
 * expected to call the corresponding "_finish()" function of the object the async function was called for, with the %AsyncResult instance.
 *
 * The purpose of the "_finish()" function is to take the generic result of type %AsyncResult and return the specific result that the operation
 * in question yields (e.g. a FileEnumerator for an "enumerate children" operation). If the result or error status of the operation is not needed,
 * there is no need to call the "_finish()" function and GIO will take care of cleaning up the result and error information after the
 * SlotAsyncReady returns. You may also store the %AsyncResult and call "_finish()" later.
 * However, the "_finish()" function may be called at most once.
 *
 * Example of a typical asynchronous operation flow:
 * @code
 * class Theoretical : public Glib::Object
 * {
 * public:
 *   Glib::RefPtr<Theoretical> create();
 *
 *   void frobnitz_async(const Gio::SlotAsyncReady& slot);
 *   Glib::ustring frobnitz_finish(const Glib::RefPtr<Gio::AsyncResult>& result);
 * // ...
 * };
 *
 * // ...
 *
 * namespace
 * {
 * Glib::RefPtr<Theoretical> theoretical;
 *
 * void on_frobnitz_ready(Glib::RefPtr<Gio::AsyncResult>& result)
 * {
 *   try
 *   {
 *     Glib::ustring s = theoretical->frobnitz_finish(result);
 *     std::cout << s << std::endl;
 *   }
 *   catch (const Glib::Error& err)
 *   {
 *     std::cerr << err.what() << std::endl;
 *   }
 *   // ...
 * }
 * } // anonymous namespace
 *
 * int main(int argc, void* argv[])
 * {
 *   // ...
 *   theoretical = Theoretical::create();
 *   theoretical->frobnitz_async(sigc::ptr_fun(&on_frobnitz_ready));
 *   // ...
 * }
 * @endcode
 *
 * The async function could also take an optional Gio::Cancellable object, allowing the calling function to cancel the asynchronous operation.
 *
 * The callback for an asynchronous operation is called only once, and is always called, even in the case of a cancelled operation.
 * On cancellation the "_finish()" function will throw a Gio::Error exception with a <tt>Gio::Error::CANCELLED</tt> error code.
 *
 * @newin{2,16}
 */

class GIOMM_API AsyncResult : public Glib::Interface
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = AsyncResult;
  using CppClassType = AsyncResult_Class;
  using BaseObjectType = GAsyncResult;
  using BaseClassType = GAsyncResultIface;

  // noncopyable
  AsyncResult(const AsyncResult&) = delete;
  auto operator=(const AsyncResult&) -> AsyncResult& = delete;

private:
  friend class AsyncResult_Class;
  static CppClassType asyncresult_class_;

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
protected:
  /**
   * You should derive from this class to use it.
   */
  AsyncResult();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  /** Called by constructors of derived classes. Provide the result of
   * the Class init() function to ensure that it is properly
   * initialized.
   *
   * @param interface_class The Class object for the derived type.
   */
  explicit AsyncResult(const Glib::Interface_Class& interface_class);

public:
  // This is public so that C++ wrapper instances can be
  // created for C instances of unwrapped types.
  // For instance, if an unexpected C type implements the C interface.
  explicit AsyncResult(GAsyncResult* castitem);

protected:
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  AsyncResult(AsyncResult&& src) noexcept;
  auto operator=(AsyncResult&& src) noexcept -> AsyncResult&;

  ~AsyncResult() noexcept override;

  static void add_interface(GType gtype_implementer);

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GAsyncResult*       { return reinterpret_cast<GAsyncResult*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GAsyncResult* { return reinterpret_cast<GAsyncResult*>(gobject_); }

private:


public:


  //Note that this returns a reference, unlike most GTK+ get_*() functions,
  //so we don't need to use refreturn.
  auto get_source_object_base() -> Glib::RefPtr<Glib::ObjectBase>;
  auto get_source_object_base() const -> Glib::RefPtr<const Glib::ObjectBase>;


  /** Checks if @a res has the given @a source_tag (generally a function
   * pointer indicating the function @a res was created by).
   *
   * @newin{2,34}
   *
   * @param source_tag An application-defined tag.
   * @return <tt>true</tt> if @a res has the indicated @a source_tag, <tt>false</tt> if
   * not.
   */
  auto is_tagged(gpointer source_tag) const -> bool;

protected:
  // The compiler cannot find an unwrap() for ObjectBase, because
  // ObjectBase::BaseObjectType is not declared.
  //#m4 __CONVERSION(`Glib::RefPtr<Glib::ObjectBase>',`GObject*',__CONVERT_REFPTR_TO_P)


    virtual auto get_source_object_vfunc() -> Glib::RefPtr<Glib::ObjectBase>;

    virtual auto is_tagged_vfunc(gpointer source_tag) -> bool;


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
   * @relates Gio::AsyncResult
   */
  GIOMM_API
  auto wrap(GAsyncResult* object, bool take_copy = false) -> Glib::RefPtr<Gio::AsyncResult>;

} // namespace Glib


#endif /* _GIOMM_ASYNCRESULT_H */

