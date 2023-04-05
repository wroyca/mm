// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_PADCONTROLLER_H
#define _GTKMM_PADCONTROLLER_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gdk/device.hxx>
#include <libmm/gio/actiongroup.hxx>
#include <libmm/gtk/eventcontroller.hxx>
#include <libmm/gtk/padactionentry.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkPadController = struct _GtkPadController;
using GtkPadControllerClass = struct _GtkPadControllerClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT PadController_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT PadController : public EventController
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = PadController;
    using CppClassType = PadController_Class;
    using BaseObjectType = GtkPadController;
    using BaseClassType = GtkPadControllerClass;

    PadController (const PadController&) = delete;
    auto
    operator= (const PadController&) -> PadController& = delete;

  private:
    friend class PadController_Class;
    static CppClassType padcontroller_class_;

  protected:
    explicit PadController (const glib::ConstructParams& construct_params);
    explicit PadController (GtkPadController* castitem);

#endif

  public:
    PadController (PadController&& src) noexcept;
    auto
    operator= (PadController&& src) noexcept -> PadController&;

    ~PadController () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkPadController*
    {
      return reinterpret_cast<GtkPadController*> (gobject_);
    }

    auto
    gobj () const -> const GtkPadController*
    {
      return reinterpret_cast<GtkPadController*> (gobject_);
    }

    auto
    gobj_copy () -> GtkPadController*;

  private:
  protected:
    explicit PadController (const glib::RefPtr<gio::ActionGroup>& action_group,
                            const glib::RefPtr<gdk::Device>& pad = {});

  public:
    static auto
    create (const glib::RefPtr<gio::ActionGroup>& action_group,
            const glib::RefPtr<gdk::Device>& pad = {})
        -> glib::RefPtr<PadController>;

    auto
    set_action_entries (const std::vector<PadActionEntry>& entries) -> void;

    auto
    set_action (PadActionType type,
                int index,
                int mode,
                const glib::ustring& label,
                const glib::ustring& action_name) -> void;

    auto
    property_action_group () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::ActionGroup>>;

    auto
    property_pad () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::Device>>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkPadController* object, bool take_copy = false) -> glib::RefPtr<gtk::PadController>;
} // namespace glib

#endif
