
#ifndef _GDKMM_CLIPBOARD_H
#define _GDKMM_CLIPBOARD_H


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

#include <libmm-glib/object.hxx>
#include <libmm-gdk/contentformats.hxx>
#include <libmm-gdk/contentprovider.hxx>
#include <libmm-gdk/display.hxx>
#include <libmm-gdk/texture.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkClipboard = struct _GdkClipboard;
using GdkClipboardClass = struct _GdkClipboardClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gdk
{ class GDKMM_API Clipboard_Class; } // namespace Gdk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{
class GDKMM_API Cancellable;
class GDKMM_API InputStream;
}

namespace Gdk
{
/** Share data between applications for Copy-and-Paste.
 *
 * The %Gdk::Clipboard object represents a clipboard of data shared
 * between different applications or between different parts of
 * the same application.
 *
 * To get a %Clipboard object, use Gdk::Display::get_clipboard() or
 * Gdk::Display::get_primary_clipboard(). You can find out about the data that
 * is currently available in a clipboard using get_formats().
 *
 * To make text or image data available in a clipboard, use set_text() or
 * set_texture(). For other data, you can use set_content(),
 * which takes a Gdk::ContentProvider object.
 *
 * To read textual or image data from a clipboard, use read_text_async() or
 * read_texture_async(). For other data, use read_async(),
 * which provides a Gio::InputStream object.
 *
 * @see Gdk::ContentProvider, Gdk::ContentFormats
 *
 * @newin{3,94}
 */

class GDKMM_API Clipboard : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = Clipboard;
  using CppClassType = Clipboard_Class;
  using BaseObjectType = GdkClipboard;
  using BaseClassType = GdkClipboardClass;

  // noncopyable
  Clipboard(const Clipboard&) = delete;
  auto operator=(const Clipboard&) -> Clipboard& = delete;

private:  friend class Clipboard_Class;
  static CppClassType clipboard_class_;

protected:
  explicit Clipboard(const Glib::ConstructParams& construct_params);
  explicit Clipboard(GdkClipboard* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  Clipboard(Clipboard&& src) noexcept;
  auto operator=(Clipboard&& src) noexcept -> Clipboard&;

  ~Clipboard() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GdkClipboard*       { return reinterpret_cast<GdkClipboard*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GdkClipboard* { return reinterpret_cast<GdkClipboard*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GdkClipboard*;

private:


public:

  /** Gets the `Gdk::Display` that the clipboard was created for.
   *
   * @return A `Gdk::Display`.
   */
  auto get_display() -> Glib::RefPtr<Display>;

  /** Gets the `Gdk::Display` that the clipboard was created for.
   *
   * @return A `Gdk::Display`.
   */
  auto get_display() const -> Glib::RefPtr<const Display>;

  /** Gets the formats that the clipboard can provide its current contents in.
   *
   * @return The formats of the clipboard.
   */
  auto get_formats() -> Glib::RefPtr<ContentFormats>;

  /** Gets the formats that the clipboard can provide its current contents in.
   *
   * @return The formats of the clipboard.
   */
  auto get_formats() const -> Glib::RefPtr<const ContentFormats>;

  /** Returns if the clipboard is local.
   *
   * A clipboard is considered local if it was last claimed
   * by the running application.
   *
   * Note that get_content() may return <tt>nullptr</tt>
   * even on a local clipboard. In this case the clipboard is empty.
   *
   * @return <tt>true</tt> if the clipboard is local.
   */
  auto is_local() const -> bool;

  /** Returns the `Gdk::ContentProvider` currently set on @a clipboard.
   *
   * If the @a clipboard is empty or its contents are not owned by the
   * current process, <tt>nullptr</tt> will be returned.
   *
   * @return The content of a clipboard
   * if the clipboard does not maintain any content.
   */
  auto get_content() -> Glib::RefPtr<ContentProvider>;

  /** Returns the `Gdk::ContentProvider` currently set on @a clipboard.
   *
   * If the @a clipboard is empty or its contents are not owned by the
   * current process, <tt>nullptr</tt> will be returned.
   *
   * @return The content of a clipboard
   * if the clipboard does not maintain any content.
   */
  auto get_content() const -> Glib::RefPtr<const ContentProvider>;

  //TODO: Wrap or ignore gdk_clipboard_store_async() and gdk_clipboard_store_finish()?
  // From the documentation of gdk_clipboard_store_async():
  // "This function is called automatically when gtk_main() or #GtkApplication
  // exit, so you likely don't need to call it."


  /** Asynchronously requests an input stream to read the @a clipboard's
   * contents from.
   *
   * When the operation is finished @a slot will be called. You must then
   * call read_finish() to get the result of the operation.
   *
   * The clipboard will choose the most suitable mime type from the given list
   * to fulfill the request, preferring the ones listed first.
   *
   * @param mime_types A <tt>nullptr</tt>-terminated array of mime types to choose from.
   * @param io_priority The I/O priority of the request.
   * @param cancellable Optional `Gio::Cancellable` object.
   * @param slot Callback to call when the request is satisfied.
   */
  void read_async(const std::vector<Glib::ustring>& mime_types, int io_priority, const Gio::SlotAsyncReady& slot, const Glib::RefPtr<Gio::Cancellable>& cancellable);

  /// A read_async() convenience overload.
  void read_async(const std::vector<Glib::ustring>& mime_types, int io_priority, const Gio::SlotAsyncReady& slot);


  /** Finishes an asynchronous clipboard read.
   *
   * See read_async().
   *
   * @param result A `Gio::AsyncResult`.
   * @param out_mime_type Location to store
   * the chosen mime type.
   * @return A `Gio::InputStream`.
   *
   * @throws Glib::Error
   */
  auto read_finish(const Glib::RefPtr<Gio::AsyncResult>& result, Glib::ustring& out_mime_type) -> Glib::RefPtr<Gio::InputStream>;


  /** Asynchronously request the @a clipboard contents converted to a `Gdk::Pixbuf`.
   *
   * When the operation is finished @a slot will be called. You must then
   * call read_texture_finish() to get the result.
   *
   * This is a simple wrapper around read_value_async().
   * Use that function or read_async() directly if you
   * need more control over the operation.
   *
   * @param cancellable Optional `Gio::Cancellable` object, <tt>nullptr</tt> to ignore.
   * @param slot Callback to call when the request is satisfied.
   */
  void read_texture_async(const Gio::SlotAsyncReady& slot, const Glib::RefPtr<Gio::Cancellable>& cancellable);

  /// A read_texture_async() convenience overload.
  void read_texture_async(const Gio::SlotAsyncReady& slot);

  /** Finishes an asynchronous clipboard read.
   *
   * See read_texture_async().
   *
   * @param result A `Gio::AsyncResult`.
   * @return A new `Gdk::Texture`.
   *
   * @throws Glib::Error
   */
  auto read_texture_finish(const Glib::RefPtr<Gio::AsyncResult>& result) -> Glib::RefPtr<Texture>;


  /** Asynchronously request the @a clipboard contents converted to a string.
   *
   * When the operation is finished @a slot will be called. You must then
   * call read_text_finish() to get the result.
   *
   * This is a simple wrapper around read_value_async().
   * Use that function or read_async() directly if you
   * need more control over the operation.
   *
   * @param cancellable Optional `Gio::Cancellable` object.
   * @param slot Callback to call when the request is satisfied.
   */
  void read_text_async(const Gio::SlotAsyncReady& slot, const Glib::RefPtr<Gio::Cancellable>& cancellable);

  /// A read_text_async() convenience overload.
  void read_text_async(const Gio::SlotAsyncReady& slot);

  /** Finishes an asynchronous clipboard read.
   *
   * See read_text_async().
   *
   * @param result A `Gio::AsyncResult`.
   * @return A new string.
   *
   * @throws Glib::Error
   */
  auto read_text_finish(const Glib::RefPtr<Gio::AsyncResult>& result) -> Glib::ustring;


  /** Sets a new content provider on @a clipboard.
   *
   * The clipboard will claim the `Gdk::Display`'s resources and advertise
   * these new contents to other applications.
   *
   * In the rare case of a failure, this function will return <tt>false</tt>. The
   * clipboard will then continue reporting its old contents and ignore
   *  @a provider.
   *
   * If the contents are read by either an external application or the
   *  @a clipboard's read functions, @a clipboard will select the best format to
   * transfer the contents and then request that format from @a provider.
   *
   * @param provider The new contents of @a clipboard
   * or <tt>nullptr</tt> to clear the clipboard.
   * @return <tt>true</tt> if setting the clipboard succeeded.
   */
  auto set_content(const Glib::RefPtr<const ContentProvider>& provider) -> bool;
  /** Clears the clipboard.
   *
   * In the rare case of a failure, this function will return <tt>false</tt>.
   * The clipboard will then continue reporting its old contents.
   *
   * @return <tt>true</tt> if unsetting the clipboard succeeded.
   */
  auto unset_content() -> bool;

  /** Puts the given @a text into the clipboard.
   *
   * @param text Text to put into the clipboard.
   */
  void set_text(const Glib::ustring& text);

  /** Puts the given @a texture into the clipboard.
   *
   * @param texture A `Gdk::Texture` to put into the clipboard.
   */
  void set_texture(const Glib::RefPtr<const Texture>& texture);

  /** The `Gdk::Display` that the clipboard belongs to.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_display() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Display> >;


  /** The possible formats that the clipboard can provide its data in.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_formats() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<ContentFormats> >;


  /** <tt>true</tt> if the contents of the clipboard are owned by this process.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_local() const -> Glib::PropertyProxy_ReadOnly< bool >;


  /** The `Gdk::ContentProvider` or <tt>nullptr</tt> if the clipboard is empty or contents are
   * provided otherwise.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_content() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<ContentProvider> >;


  // no_default_handler because GdkClipbaordClass is private.

  /**
   * @par Slot Prototype:
   * <tt>void on_my_%changed()</tt>
   *
   * Flags: Run Last
   *
   * Emitted when the clipboard changes ownership.
   */

  auto signal_changed() -> Glib::SignalProxy<void()>;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


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
   * @relates Gdk::Clipboard
   */
  GDKMM_API
  auto wrap(GdkClipboard* object, bool take_copy = false) -> Glib::RefPtr<Gdk::Clipboard>;
}


#endif /* _GDKMM_CLIPBOARD_H */

