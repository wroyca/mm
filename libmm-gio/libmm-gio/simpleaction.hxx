// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_SIMPLEACTION_H
#define _GIOMM_SIMPLEACTION_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/action.hxx>
#include <libmm-glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GSimpleAction GSimpleAction;
using GSimpleActionClass = GObjectClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class GIOMM_API SimpleAction_Class;
}
#endif

namespace Gio
{

  class GIOMM_API SimpleAction : public Glib::Object,
                                 public Action
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = SimpleAction;
    using CppClassType = SimpleAction_Class;
    using BaseObjectType = GSimpleAction;
    using BaseClassType = GSimpleActionClass;

    SimpleAction (const SimpleAction&) = delete;
    auto
    operator= (const SimpleAction&) -> SimpleAction& = delete;

  private:
    friend class SimpleAction_Class;
    static CppClassType simpleaction_class_;

  protected:
    explicit SimpleAction (const Glib::ConstructParams& construct_params);
    explicit SimpleAction (GSimpleAction* castitem);

#endif

  public:
    SimpleAction (SimpleAction&& src) noexcept;
    auto
    operator= (SimpleAction&& src) noexcept -> SimpleAction&;

    ~SimpleAction () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GSimpleAction*
    {
      return reinterpret_cast<GSimpleAction*> (gobject_);
    }

    auto
    gobj () const -> const GSimpleAction*
    {
      return reinterpret_cast<GSimpleAction*> (gobject_);
    }

    auto
    gobj_copy () -> GSimpleAction*;

  private:
  protected:
    explicit SimpleAction (const Glib::ustring& name);

    SimpleAction (const Glib::ustring& name, const Glib::VariantBase& state);

    explicit SimpleAction (const Glib::ustring& name,
                           const Glib::VariantType& parameter_type);

    explicit SimpleAction (const Glib::ustring& name,
                           const Glib::VariantType& parameter_type,
                           const Glib::VariantBase& state);

  public:
    static auto
    create (const Glib::ustring& name) -> Glib::RefPtr<SimpleAction>;

    static auto
    create (const Glib::ustring& name, const Glib::VariantType& parameter_type)
        -> Glib::RefPtr<SimpleAction>;

    static auto
    create (const Glib::ustring& name,
            const Glib::VariantType& parameter_type,
            const Glib::VariantBase& state) -> Glib::RefPtr<SimpleAction>;

    static auto
    create (const Glib::ustring& name, const Glib::VariantBase& state)
        -> Glib::RefPtr<SimpleAction>;

    static auto
    create_bool (const Glib::ustring& name, bool state = false)
        -> Glib::RefPtr<SimpleAction>;

    static auto
    create_radio_string (const Glib::ustring& name,
                         const Glib::ustring& initial_state)
        -> Glib::RefPtr<SimpleAction>;

    static auto
    create_radio_integer (const Glib::ustring& name, gint32 initial_state)
        -> Glib::RefPtr<SimpleAction>;

    auto
    set_enabled (bool enabled = true) -> void;

    auto
    set_state (const Glib::VariantBase& value) -> void;

    auto
    set_state_hint (const Glib::VariantBase& state_hint) -> void;

    auto
    property_enabled () -> Glib::PropertyProxy<bool>;

    auto
    property_enabled () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_parameter_type () const
        -> Glib::PropertyProxy_ReadOnly<Glib::VariantType>;

    auto
    property_state () -> Glib::PropertyProxy<Glib::VariantBase>;

    auto
    property_state () const -> Glib::PropertyProxy_ReadOnly<Glib::VariantBase>;

    auto
    property_state_type () const
        -> Glib::PropertyProxy_ReadOnly<Glib::VariantType>;

    auto
    signal_activate () -> Glib::SignalProxy<void (const Glib::VariantBase&)>;

    auto
    signal_change_state ()
        -> Glib::SignalProxy<void (const Glib::VariantBase&)>;

  public:
  public:
  protected:
  };

} // namespace Gio

namespace Glib
{

  GIOMM_API
  auto
  wrap (GSimpleAction* object, bool take_copy = false) -> Glib::RefPtr<Gio::SimpleAction>;
} // namespace Glib

#endif
