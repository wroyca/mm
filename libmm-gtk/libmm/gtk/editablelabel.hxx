// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_EDITABLELABEL_H
#define _GTKMM_EDITABLELABEL_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/editable.hxx>
#include <libmm/gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT EditableLabel_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT EditableLabel : public Widget,
                                  public Editable
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef EditableLabel CppObjectType;
    typedef EditableLabel_Class CppClassType;
    typedef GtkEditableLabel BaseObjectType;
    typedef GtkEditableLabelClass BaseClassType;
#endif

    EditableLabel (EditableLabel&& src) noexcept;
    auto
    operator= (EditableLabel&& src) noexcept -> EditableLabel&;

    EditableLabel (const EditableLabel&) = delete;
    auto
    operator= (const EditableLabel&) -> EditableLabel& = delete;

    ~EditableLabel () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class EditableLabel_Class;
    static CppClassType editablelabel_class_;

  protected:
    explicit EditableLabel (const glib::ConstructParams& construct_params);
    explicit EditableLabel (GtkEditableLabel* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkEditableLabel*
    {
      return reinterpret_cast<GtkEditableLabel*> (gobject_);
    }

    auto
    gobj () const -> const GtkEditableLabel*
    {
      return reinterpret_cast<GtkEditableLabel*> (gobject_);
    }

  private:
  public:
    EditableLabel ();

    explicit EditableLabel (const glib::ustring& text);

    auto
    get_editing () const -> bool;

    auto
    start_editing () -> void;

    auto
    stop_editing (bool commit) -> void;

    auto
    property_editing () -> glib::PropertyProxy<bool>;

    auto
    property_editing () const -> glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkEditableLabel* object, bool take_copy = false) -> gtk::EditableLabel*;
} // namespace glib

#endif
