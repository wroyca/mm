
#ifndef _GDKMM_CONTENTPROVIDER_H
#define _GDKMM_CONTENTPROVIDER_H


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/* Copyright (C) 2017 The gtkmm Development Team
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
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */


#include <libmm-glib/bytes.hxx>
#include <libmm-glib/object.hxx>
#include <libmm-glib/refptr.hxx>
#include <libmm-gio/asyncresult.hxx>
#include <libmm-gio/cancellable.hxx>
#include <libmm-gdk/contentformats.hxx>
#include <memory>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkContentProvider = struct _GdkContentProvider;
using GdkContentProviderClass = struct _GdkContentProviderClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gdk
{ class GDKMM_API ContentProvider_Class; } // namespace Gdk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{
class GDKMM_API OutputStream;
}

namespace Gdk
{

/** Provides content for data transfer between applications.
 *
 * A %Gdk::ContentProvider is used to provide content for the clipboard in
 * a number of formats.
 *
 * To create a %ContentProvider, use one of the overloaded create() methods.
 *
 * GDK knows how to handle common text and image formats out-of-the-box. See
 * Gdk::ContentSerializer and Gdk::ContentDeserializer if you want to add support
 * for application-specific data formats.
 *
 * @see Gdk::ContentSerializer, Gdk::ContentDeserializer
 *
 * @newin{3,94}
 */

class GDKMM_API ContentProvider : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = ContentProvider;
  using CppClassType = ContentProvider_Class;
  using BaseObjectType = GdkContentProvider;
  using BaseClassType = GdkContentProviderClass;

  // noncopyable
  ContentProvider(const ContentProvider&) = delete;
  auto operator=(const ContentProvider&) -> ContentProvider& = delete;

private:  friend class ContentProvider_Class;
  static CppClassType contentprovider_class_;

protected:
  explicit ContentProvider(const Glib::ConstructParams& construct_params);
  explicit ContentProvider(GdkContentProvider* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  ContentProvider(ContentProvider&& src) noexcept;
  auto operator=(ContentProvider&& src) noexcept -> ContentProvider&;

  ~ContentProvider() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GdkContentProvider*       { return reinterpret_cast<GdkContentProvider*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GdkContentProvider* { return reinterpret_cast<GdkContentProvider*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GdkContentProvider*;

private:


protected:
  ContentProvider();

public:
  // _WRAP_METHOD is used for the create() methods because the gdk_content_provider_new_*()
  // functions do more than call g_object_new().

  /** Create a content provider that provides the given @a value.
   *
   * @param value A `Glib::Value`.
   * @return A new `Gdk::ContentProvider`.
   */
  static auto create(const Glib::ValueBase& value) -> Glib::RefPtr<ContentProvider>;

  /** Creates a content provider that represents all the given @a providers.
   *
   * Whenever data needs to be written, the union provider will try the given
   *  @a providers in the given order and the first one supporting a format will
   * be chosen to provide it.
   *
   * This allows an easy way to support providing data in different formats.
   * For example, an image may be provided by its file and by the image
   * contents with a call such as
   *
   * [C example ellipted]
   *
   * @param providers The `Gdk::ContentProvider`s to present the union of.
   * @param n_providers The number of providers.
   * @return A new `Gdk::ContentProvider`.
   */

  static auto create(const std::vector<Glib::RefPtr<ContentProvider>>& providers) -> Glib::RefPtr<ContentProvider>;

  /** Create a content provider that provides the given @a bytes as data for
   * the given @a mime_type.
   *
   * @param mime_type The mime type.
   * @param bytes A `Glib::Bytes` with the data for @a mime_type.
   * @return A new `Gdk::ContentProvider`.
   */
  static auto create(const Glib::ustring& mime_type, const Glib::RefPtr<const Glib::Bytes>& bytes) -> Glib::RefPtr<ContentProvider>;

  // ref_formats() and ref_storable_formats() are const because they return
  // newly created ContentFormats instances.

  /** Gets the formats that the provider can provide its current contents in.
   *
   * @return The formats of the provider.
   */
  auto ref_formats() const -> Glib::RefPtr<ContentFormats>;

  /** Gets the formats that the provider suggests other applications to store
   * the data in.
   *
   * An example of such an application would be a clipboard manager.
   *
   * This can be assumed to be a subset of ref_formats().
   *
   * @return The storable formats of the provider.
   */
  auto ref_storable_formats() const -> Glib::RefPtr<ContentFormats>;


  /** Emits the signal_content_changed() signal.
   */
  void content_changed();


  /** Asynchronously writes the contents of @a provider to @a stream in the given
   *  @a mime_type.
   *
   * When the operation is finished @a slot will be called. You must then call
   * write_mime_type_finish() to get the result
   * of the operation.
   *
   * The given mime type does not need to be listed in the formats returned by
   * ref_formats(). However, if the given `GType` is
   * not supported, `Gio::Error::NOT_SUPPORTED` will be reported.
   *
   * The given @a stream will not be closed.
   *
   * @param mime_type The mime type to provide the data in.
   * @param stream The `Gio::OutputStream` to write to.
   * @param io_priority I/O priority of the request.
   * @param cancellable Optional `Gio::Cancellable` object, <tt>nullptr</tt> to ignore.
   * @param slot Callback to call when the request is satisfied.
   */
  void write_mime_type_async(const Glib::ustring& mime_type, const Glib::RefPtr<Gio::OutputStream>& stream, int io_priority, const Gio::SlotAsyncReady& slot, const Glib::RefPtr<Gio::Cancellable>& cancellable) const;

  /// A write_mime_type_async() convenience overload.
  void write_mime_type_async(const Glib::ustring& mime_type, const Glib::RefPtr<Gio::OutputStream>& stream, int io_priority, const Gio::SlotAsyncReady& slot) const;

  /** Finishes an asynchronous write operation.
   *
   * See write_mime_type_async().
   *
   * @param result A `Gio::AsyncResult`.
   *
   * @throws Glib::Error
   */
  void write_mime_type_finish(const Glib::RefPtr<Gio::AsyncResult>& result) const;


  /** Gets the contents of @a provider stored in @a value.
   *
   * The @a value will have been initialized to the `GType` the value should be
   * provided in. This given `GType` does not need to be listed in the formats
   * returned by ref_formats(). However, if the
   * given `GType` is not supported, this operation can fail and
   * `Gio::Error::NOT_SUPPORTED` will be reported.
   *
   * @param value The `Glib::Value` to fill.
   *
   * @throws Glib::Error
   */
  void get_value(Glib::ValueBase& value) const;

  /** The possible formats that the provider can provide its data in.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_formats() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<ContentFormats> >;


  /** The subset of formats that clipboard managers should store this provider's data in.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_storable_formats() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<ContentFormats> >;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%content_changed()</tt>
   *
   * Flags: Run Last
   *
   * Emitted whenever the content provided by this provider has changed.
   */

  auto signal_content_changed() -> Glib::SignalProxy<void()>;


  // GdkContentProvider contains vfuncs, but it's no use wrapping them as long as
  // there is no constructor that calls g_object_new() to create a gtkmm__GdkContentProvider
  // instance. A GdkContentProvider instance never calls an overriding vfunc in
  // Gdk::ContentProvider.


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_content_changed().
  virtual void on_content_changed();


};

} // namespace Gdk


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gdk::ContentProvider
   */
  GDKMM_API
  auto wrap(GdkContentProvider* object, bool take_copy = false) -> Glib::RefPtr<Gdk::ContentProvider>;
}


#endif /* _GDKMM_CONTENTPROVIDER_H */
