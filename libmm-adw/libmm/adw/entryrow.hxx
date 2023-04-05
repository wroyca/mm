// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_ENTRYROW_H
#define _LIBADWAITAMM_ENTRYROW_H

#include <libmm/adw/mm-adwconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/adw/preferencesrow.hxx>

#include <adwaita.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace adw
{
  class LIBMM_ADW_SYMEXPORT EntryRow_Class;
}
#endif

namespace adw
{

  class LIBMM_ADW_SYMEXPORT EntryRow : public adw::PreferencesRow,
                   public gtk::Editable
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef EntryRow CppObjectType;
    typedef EntryRow_Class CppClassType;
    typedef AdwEntryRow BaseObjectType;
    typedef AdwEntryRowClass BaseClassType;
#endif

    EntryRow (EntryRow&& src) noexcept;
    auto
    operator= (EntryRow&& src) noexcept -> EntryRow&;

    EntryRow (const EntryRow&) = delete;
    auto
    operator= (const EntryRow&) -> EntryRow& = delete;

    ~EntryRow () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend class EntryRow_Class;
    static CppClassType entryrow_class_;

  protected:
    explicit EntryRow (const glib::ConstructParams& construct_params);
    explicit EntryRow (AdwEntryRow* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> AdwEntryRow*
    {
      return reinterpret_cast<AdwEntryRow*> (gobject_);
    }

    auto
    gobj () const -> const AdwEntryRow*
    {
      return reinterpret_cast<AdwEntryRow*> (gobject_);
    }

  private:
  public:
    EntryRow ();

    auto
    add_prefix (gtk::Widget* widget) -> void;

    auto
    add_suffix (gtk::Widget* widget) -> void;

    auto
    get_activates_default () const -> bool;

    auto
    get_attributes () const -> pango::AttrList;

    auto
    get_enable_moji_completion () const -> bool;

    auto
    get_input_hints () const -> gtk::InputHints;

    auto
    get_input_purpose () const -> gtk::InputPurpose;

    auto
    get_show_apply_button () const -> bool;

    auto
    remove (gtk::Widget* widget) -> void;

    auto
    set_activates_default (bool activates) -> void;

    auto
    set_attributes (pango::AttrList& attributes) -> void;

    auto
    set_enable_emoji_completion (bool activates) -> void;

    auto
    set_input_hints (gtk::InputHints hints) -> void;

    auto
    set_input_purpose (gtk::InputPurpose purpose) -> void;

    auto
    set_show_apply_button (bool activates) -> void;

    auto
    property_activates_default () -> glib::PropertyProxy<bool>;

    auto
    property_activates_default () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_attributes () -> glib::PropertyProxy<pango::AttrList>;

    auto
    property_attributes () const
        -> glib::PropertyProxy_ReadOnly<pango::AttrList>;

    auto
    property_enable_emoji_completion () -> glib::PropertyProxy<bool>;

    auto
    property_enable_emoji_completion () const
        -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_input_hints () -> glib::PropertyProxy<gtk::InputHints>;

    auto
    property_input_hints () const
        -> glib::PropertyProxy_ReadOnly<gtk::InputHints>;

    auto
    property_input_purpose () -> glib::PropertyProxy<gtk::InputPurpose>;

    auto
    property_input_purpose () const
        -> glib::PropertyProxy_ReadOnly<gtk::InputPurpose>;

    auto
    property_show_apply_button () -> glib::PropertyProxy<bool>;

    auto
    property_show_apply_button () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    signal_apply () -> glib::SignalProxy<void ()>;

    auto
    signal_entry_activated () -> glib::SignalProxy<void ()>;

  public:
  public:
  protected:
  };

} // namespace adw

namespace glib
{

  auto
  wrap (AdwEntryRow* object, bool take_copy = false) -> adw::EntryRow*;
}

#endif
