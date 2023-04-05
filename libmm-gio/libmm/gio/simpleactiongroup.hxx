// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_SIMPLEACTIONGROUP_H
#define _GIOMM_SIMPLEACTIONGROUP_H

#include <libmm/gio/mm-gioconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/actiongroup.hxx>
#include <libmm/gio/actionmap.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GSimpleActionGroup = struct _GSimpleActionGroup;
using GSimpleActionGroupClass = struct _GSimpleActionGroupClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio
{
  class LIBMM_GIO_SYMEXPORT SimpleActionGroup_Class;
}
#endif

namespace gio
{

  class LIBMM_GIO_SYMEXPORT Action;

  class LIBMM_GIO_SYMEXPORT SimpleActionGroup : public glib::Object,
                                      public ActionGroup,
                                      public ActionMap
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = SimpleActionGroup;
    using CppClassType = SimpleActionGroup_Class;
    using BaseObjectType = GSimpleActionGroup;
    using BaseClassType = GSimpleActionGroupClass;

    SimpleActionGroup (const SimpleActionGroup&) = delete;
    auto
    operator= (const SimpleActionGroup&) -> SimpleActionGroup& = delete;

  private:
    friend class SimpleActionGroup_Class;
    static CppClassType simpleactiongroup_class_;

  protected:
    explicit SimpleActionGroup (const glib::ConstructParams& construct_params);
    explicit SimpleActionGroup (GSimpleActionGroup* castitem);

#endif

  public:
    SimpleActionGroup (SimpleActionGroup&& src) noexcept;
    auto
    operator= (SimpleActionGroup&& src) noexcept -> SimpleActionGroup&;

    ~SimpleActionGroup () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GSimpleActionGroup*
    {
      return reinterpret_cast<GSimpleActionGroup*> (gobject_);
    }

    auto
    gobj () const -> const GSimpleActionGroup*
    {
      return reinterpret_cast<GSimpleActionGroup*> (gobject_);
    }

    auto
    gobj_copy () -> GSimpleActionGroup*;

  private:
  protected:
    SimpleActionGroup ();

  public:
    static auto
    create () -> glib::RefPtr<SimpleActionGroup>;

  public:
  public:
  protected:
  };

} // namespace gio

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GSimpleActionGroup* object, bool take_copy = false) -> glib::RefPtr<gio::SimpleActionGroup>;
} // namespace glib

#endif
