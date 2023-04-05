// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_ACTIONMAP_H
#define _GIOMM_ACTIONMAP_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/simpleaction.hxx>
#include <libmm/glib/interface.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GActionMapInterface GActionMapInterface;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GActionMap = struct _GActionMap;
using GActionMapClass = struct _GActionMapClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio
{
  class LIBMM_GIO_SYMEXPORT ActionMap_Class;
}
#endif

namespace gio
{

  class LIBMM_GIO_SYMEXPORT Action;

  class LIBMM_GIO_SYMEXPORT ActionMap : public glib::Interface
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

    explicit ActionMap (const glib::Interface_Class& interface_class);

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
    add_action (const glib::RefPtr<Action>& action) -> void;

    auto
    remove_action (const glib::ustring& action_name) -> void;

    auto
    lookup_action (const glib::ustring& action_name) -> glib::RefPtr<Action>;

    auto
    lookup_action (const glib::ustring& action_name) const
        -> glib::RefPtr<const Action>;

    auto
    add_action (const glib::ustring& name) -> glib::RefPtr<SimpleAction>;

    using ActivateSlot = sigc::slot<void ()>;

    auto
    add_action (const glib::ustring& name, const ActivateSlot& slot)
        -> glib::RefPtr<SimpleAction>;

    using ActivateWithParameterSlot =
        sigc::slot<void (const glib::VariantBase&)>;

    auto
    add_action_with_parameter (const glib::ustring& name,
                               const glib::VariantType& parameter_type,
                               const ActivateWithParameterSlot& slot)
        -> glib::RefPtr<SimpleAction>;

    auto
    add_action_bool (const glib::ustring& name, bool state = false)
        -> glib::RefPtr<SimpleAction>;

    auto
    add_action_bool (const glib::ustring& name,
                     const ActivateSlot& slot,
                     bool state = false) -> glib::RefPtr<SimpleAction>;

    auto
    add_action_radio_string (const glib::ustring& name,
                             const glib::ustring& state)
        -> glib::RefPtr<SimpleAction>;

    using ActivateWithStringParameterSlot =
        sigc::slot<void (const glib::ustring&)>;

    auto
    add_action_radio_string (const glib::ustring& name,
                             const ActivateWithStringParameterSlot& slot,
                             const glib::ustring& state)
        -> glib::RefPtr<SimpleAction>;

    auto
    add_action_radio_integer (const glib::ustring& name, gint32 state)
        -> glib::RefPtr<SimpleAction>;

    using ActivateWithIntParameterSlot = sigc::slot<void (int)>;

    auto
    add_action_radio_integer (const glib::ustring& name,
                              const ActivateWithIntParameterSlot& slot,
                              gint32 state) -> glib::RefPtr<SimpleAction>;

  protected:
    virtual auto
    lookup_action_vfunc (const glib::ustring& name) const
        -> glib::RefPtr<Action>;

    virtual auto
    add_action_vfunc (const glib::RefPtr<Action>& action) const -> void;

    virtual auto
    remove_action_vfunc (const glib::ustring& name) -> void;

  public:
  public:
  protected:
  };

} // namespace gio

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GActionMap* object, bool take_copy = false) -> glib::RefPtr<gio::ActionMap>;

} // namespace glib

#endif
