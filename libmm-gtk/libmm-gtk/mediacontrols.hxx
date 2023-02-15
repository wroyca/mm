// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_MEDIACONTROLS_H
#define _GTKMM_MEDIACONTROLS_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/mediastream.hxx>
#include <libmm-gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API MediaControls_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API MediaControls : public Widget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef MediaControls CppObjectType;
    typedef MediaControls_Class CppClassType;
    typedef GtkMediaControls BaseObjectType;
    typedef GtkMediaControlsClass BaseClassType;
#endif

    MediaControls (MediaControls&& src) noexcept;
    auto
    operator= (MediaControls&& src) noexcept -> MediaControls&;

    MediaControls (const MediaControls&) = delete;
    auto
    operator= (const MediaControls&) -> MediaControls& = delete;

    ~MediaControls () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend GTKMM_API class MediaControls_Class;
    static CppClassType mediacontrols_class_;

  protected:
    explicit MediaControls (const Glib::ConstructParams& construct_params);
    explicit MediaControls (GtkMediaControls* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkMediaControls*
    {
      return reinterpret_cast<GtkMediaControls*> (gobject_);
    }

    auto
    gobj () const -> const GtkMediaControls*
    {
      return reinterpret_cast<GtkMediaControls*> (gobject_);
    }

  private:
  public:
    MediaControls ();
    explicit MediaControls (const Glib::RefPtr<MediaStream>& media_stream);

    auto
    get_media_stream () -> Glib::RefPtr<MediaStream>;

    auto
    get_media_stream () const -> Glib::RefPtr<const MediaStream>;

    auto
    set_media_stream (const Glib::RefPtr<MediaStream>& stream) -> void;

    auto
    property_media_stream () -> Glib::PropertyProxy<Glib::RefPtr<MediaStream>>;

    auto
    property_media_stream () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<MediaStream>>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  GTKMM_API auto
  wrap (GtkMediaControls* object, bool take_copy = false) -> Gtk::MediaControls*;
} // namespace Glib

#endif
