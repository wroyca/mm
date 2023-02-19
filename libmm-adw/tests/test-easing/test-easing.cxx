/*
 * Copyright (C) 2021 Purism SPC
 *
 * SPDX-License-Identifier: LGPL-2.1-or-later
 *
 * Author: Alexander Mikhaylenko <alexander.mikhaylenko@puri.sm>
 */

#include <libmm-adw/init.hxx> // Adw::init
#include <libmm-adw/mm-adw.hxx>

static void
test_easing_ease (gconstpointer data)
{
  Adw::Easing easing = static_cast<Adw::Easing> (GPOINTER_TO_INT (data));

  g_assert_cmpfloat_with_epsilon (Adw::ease (easing, 0), 0, 0.005);
  g_assert_cmpfloat_with_epsilon (Adw::ease (easing, 1), 1, 0.005);
}

int
main (int argc, char* argv[])
{
  gtk_test_init (&argc, &argv, NULL);
  Adw::init ();

  // This does not seem wrapped at all in gtkmm.
  GEnumClass* enum_class = (GEnumClass*) g_type_class_ref (ADW_TYPE_EASING);

  for (guint i = 0; i < enum_class->n_values; i++)
  {
    GEnumValue* value = &enum_class->values[i];
    char* path = g_strdup_printf ("/Adwaita/Easing/%s", value->value_nick);

    g_test_add_data_func (path,
                          GINT_TO_POINTER (value->value),
                          test_easing_ease);

    g_free (path);
  }

  g_type_class_unref (enum_class);

  return g_test_run ();
}
