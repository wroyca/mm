
#ifndef _GTKMM_MEDIACONTROLS_H
#define _GTKMM_MEDIACONTROLS_H


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/* Copyright (C) 2018 The gtkmm Development Team
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

#include <libmm-gtk/widget.hxx>
#include <libmm-gtk/mediastream.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API MediaControls_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/**  A widget showing controls for a media stream.
 *
 * %Gtk::MediaControls is a widget to show controls for a Gtk::MediaStream
 * and giving users a way to use it.
 *
 * @ingroup Widgets
 *
 * @newin{3,94}
 */

class GTKMM_API MediaControls : public Widget
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef MediaControls CppObjectType;
  typedef MediaControls_Class CppClassType;
  typedef GtkMediaControls BaseObjectType;
  typedef GtkMediaControlsClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  MediaControls(MediaControls&& src) noexcept;
  auto operator=(MediaControls&& src) noexcept -> MediaControls&;

  // noncopyable
  MediaControls(const MediaControls&) = delete;
  auto operator=(const MediaControls&) -> MediaControls& = delete;

  ~MediaControls() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class MediaControls_Class;
  static CppClassType mediacontrols_class_;

protected:
  explicit MediaControls(const Glib::ConstructParams& construct_params);
  explicit MediaControls(GtkMediaControls* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkMediaControls*       { return reinterpret_cast<GtkMediaControls*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkMediaControls* { return reinterpret_cast<GtkMediaControls*>(gobject_); }

private:


public:
  MediaControls();
    explicit MediaControls(const Glib::RefPtr<MediaStream>& media_stream);


  /** Gets the media stream managed by @a controls or <tt>nullptr</tt> if none.
   *
   * @return The media stream managed by @a controls.
   */
  auto get_media_stream() -> Glib::RefPtr<MediaStream>;

  /** Gets the media stream managed by @a controls or <tt>nullptr</tt> if none.
   *
   * @return The media stream managed by @a controls.
   */
  auto get_media_stream() const -> Glib::RefPtr<const MediaStream>;

  /** Sets the stream that is controlled by @a controls.
   *
   * @param stream A `Gtk::MediaStream`.
   */
  void set_media_stream(const Glib::RefPtr<MediaStream>& stream);

  /** The media-stream managed by this object or <tt>nullptr</tt> if none.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_media_stream() -> Glib::PropertyProxy< Glib::RefPtr<MediaStream> > ;

/** The media-stream managed by this object or <tt>nullptr</tt> if none.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_media_stream() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<MediaStream> >;


  // There are no signals or vfuncs.


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} //namespace Gtk


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::MediaControls
   */
  GTKMM_API
  auto wrap(GtkMediaControls* object, bool take_copy = false) -> Gtk::MediaControls*;
} //namespace Glib


#endif /* _GTKMM_MEDIACONTROLS_H */

