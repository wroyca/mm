// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_ACTIONMAP_H
#define _GIOMM_ACTIONMAP_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/simpleaction.hxx>
#include <libmm-glib/interface.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GActionMapInterface GActionMapInterface;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GActionMap = struct _GActionMap;
using GActionMapClass = struct _GActionMapClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class LIBMM_GIO_SYMEXPORT ActionMap_Class;
}
#endif

namespace Gio
{

  class LIBMM_GIO_SYMEXPORT Action;

  class LIBMM_GIO_SYMEXPORT ActionMap : public Glib::Interface
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = ActionMap;
    using CppClassType = ActionMap_Class;
    using BaseObjectType = GActionMap;
    using BaseClassType = GActionMapInterface;

    ActionMap (const ActionMap&) = delete;
    auto
    operator= (const ActionMap&) -> ActionMap& = delete;

  private:
    friend class ActionMap_Class;
    static CppClassType actionmap_class_;

#endif
  protected:
    ActionMap ();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    explicit ActionMap (const Glib::Interface_Class& interface_class);

  public:
    explicit ActionMap (GActionMap* castitem);

  protected:
#endif

  public:
    ActionMap (ActionMap&& src) noexcept;
    auto
    operator= (ActionMap&& src) noexcept -> ActionMap&;

    ~ActionMap () noexcept override;

    static auto
    add_interface (GType gtype_implementer) -> void;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GActionMap*
    {
      return reinterpret_cast<GActionMap*> (gobject_);
    }

    auto
    gobj () const -> const GActionMap*
    {
      return reinterpret_cast<GActionMap*> (gobject_);
    }

  private:
  public:
    auto
    add_action (const Glib::RefPtr<Action>& action) -> void;

    auto
    remove_action (const Glib::ustring& action_name) -> void;

    auto
    lookup_action (const Glib::ustring& action_name) -> Glib::RefPtr<Action>;

    auto
    lookup_action (const Glib::ustring& action_name) const
        -> Glib::RefPtr<const Action>;

    auto
    add_action (const Glib::ustring& name) -> Glib::RefPtr<SimpleAction>;

    using ActivateSlot = sigc::slot<void ()>;

    auto
    add_action (const Glib::ustring& name, const ActivateSlot& slot)
        -> Glib::RefPtr<SimpleAction>;

    using ActivateWithParameterSlot =
        sigc::slot<void (const Glib::VariantBase&)>;

    auto
    add_action_with_parameter (const Glib::ustring& name,
                               const Glib::VariantType& parameter_type,
                               const ActivateWithParameterSlot& slot)
        -> Glib::RefPtr<SimpleAction>;

    auto
    add_action_bool (const Glib::ustring& name, bool state = false)
        -> Glib::RefPtr<SimpleAction>;

    auto
    add_action_bool (const Glib::ustring& name,
                     const ActivateSlot& slot,
                     bool state = false) -> Glib::RefPtr<SimpleAction>;

    auto
    add_action_radio_string (const Glib::ustring& name,
                             const Glib::ustring& state)
        -> Glib::RefPtr<SimpleAction>;

    using ActivateWithStringParameterSlot =
        sigc::slot<void (const Glib::ustring&)>;

    auto
    add_action_radio_string (const Glib::ustring& name,
                             const ActivateWithStringParameterSlot& slot,
                             const Glib::ustring& state)
        -> Glib::RefPtr<SimpleAction>;

    auto
    add_action_radio_integer (const Glib::ustring& name, gint32 state)
        -> Glib::RefPtr<SimpleAction>;

    using ActivateWithIntParameterSlot = sigc::slot<void (int)>;

    auto
    add_action_radio_integer (const Glib::ustring& name,
                              const ActivateWithIntParameterSlot& slot,
                              gint32 state) -> Glib::RefPtr<SimpleAction>;

  protected:
    virtual auto
    lookup_action_vfunc (const Glib::ustring& name) const
        -> Glib::RefPtr<Action>;

    virtual auto
    add_action_vfunc (const Glib::RefPtr<Action>& action) const -> void;

    virtual auto
    remove_action_vfunc (const Glib::ustring& name) -> void;

  public:
  public:
  protected:
  };

} // namespace Gio

namespace Glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GActionMap* object, bool take_copy = false) -> Glib::RefPtr<Gio::ActionMap>;

} // namespace Glib

#endif
