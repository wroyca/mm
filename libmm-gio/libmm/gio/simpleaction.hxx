// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_SIMPLEACTION_H
#define _GIOMM_SIMPLEACTION_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/action.hxx>
#include <libmm/glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GSimpleAction GSimpleAction;
using GSimpleActionClass = GObjectClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio
{
  class LIBMM_GIO_SYMEXPORT SimpleAction_Class;
}
#endif

namespace gio
{

  class LIBMM_GIO_SYMEXPORT SimpleAction : public glib::Object,
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
    explicit SimpleAction (const glib::ConstructParams& construct_params);
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
    explicit SimpleAction (const glib::ustring& name);

    SimpleAction (const glib::ustring& name, const glib::VariantBase& state);

    explicit SimpleAction (const glib::ustring& name,
                           const glib::VariantType& parameter_type);

    explicit SimpleAction (const glib::ustring& name,
                           const glib::VariantType& parameter_type,
                           const glib::VariantBase& state);

  public:
    static auto
    create (const glib::ustring& name) -> glib::RefPtr<SimpleAction>;

    static auto
    create (const glib::ustring& name, const glib::VariantType& parameter_type)
        -> glib::RefPtr<SimpleAction>;

    static auto
    create (const glib::ustring& name,
            const glib::VariantType& parameter_type,
            const glib::VariantBase& state) -> glib::RefPtr<SimpleAction>;

    static auto
    create (const glib::ustring& name, const glib::VariantBase& state)
        -> glib::RefPtr<SimpleAction>;

    static auto
    create_bool (const glib::ustring& name, bool state = false)
        -> glib::RefPtr<SimpleAction>;

    static auto
    create_radio_string (const glib::ustring& name,
                         const glib::ustring& initial_state)
        -> glib::RefPtr<SimpleAction>;

    static auto
    create_radio_integer (const glib::ustring& name, gint32 initial_state)
        -> glib::RefPtr<SimpleAction>;

    auto
    set_enabled (bool enabled = true) -> void;

    auto
    set_state (const glib::VariantBase& value) -> void;

    auto
    set_state_hint (const glib::VariantBase& state_hint) -> void;

    auto
    property_enabled () -> glib::PropertyProxy<bool>;

    auto
    property_enabled () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_parameter_type () const
        -> glib::PropertyProxy_ReadOnly<glib::VariantType>;

    auto
    property_state () -> glib::PropertyProxy<glib::VariantBase>;

    auto
    property_state () const -> glib::PropertyProxy_ReadOnly<glib::VariantBase>;

    auto
    property_state_type () const
        -> glib::PropertyProxy_ReadOnly<glib::VariantType>;

    auto
    signal_activate () -> glib::SignalProxy<void (const glib::VariantBase&)>;

    auto
    signal_change_state ()
        -> glib::SignalProxy<void (const glib::VariantBase&)>;

  public:
  public:
  protected:
  };

} // namespace gio

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GSimpleAction* object, bool take_copy = false) -> glib::RefPtr<gio::SimpleAction>;
} // namespace glib

#endif
