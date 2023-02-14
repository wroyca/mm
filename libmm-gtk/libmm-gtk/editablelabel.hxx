
#ifndef _GTKMM_EDITABLELABEL_H
#define _GTKMM_EDITABLELABEL_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/editable.hxx>
#include <libmm-gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API EditableLabel_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API EditableLabel : public Widget,
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
    friend GTKMM_API class EditableLabel_Class;
    static CppClassType editablelabel_class_;

  protected:
    explicit EditableLabel (const Glib::ConstructParams& construct_params);
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

    explicit EditableLabel (const Glib::ustring& text);

    auto
    get_editing () const -> bool;

    void
    start_editing ();

    void
    stop_editing (bool commit);

    auto
    property_editing () -> Glib::PropertyProxy<bool>;

    auto
    property_editing () const -> Glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkEditableLabel* object, bool take_copy = false) -> Gtk::EditableLabel*;
} // namespace Glib

#endif
