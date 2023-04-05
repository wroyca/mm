/*
 * Copyright (C) 2022 Purism SPC
 *
 * SPDX-License-Identifier: LGPL-2.1-or-later
 *
 * Author: Alexander Mikhaylenko <alexander.mikhaylenko@puri.sm>
 */

#include <libmm/adw/init.hxx> // adw::init
#include <libmm/adw/mm-adw.hxx>
#include <vector>

static void
test_adw_about_window_create (void)
{
  adw::AboutWindow* window = new adw::AboutWindow ();
  g_assert_nonnull (window);

  std::vector<glib::ustring> developers{"Angela Avery"};
  std::vector<glib::ustring> designers{"GNOME Design Team"};
  std::vector<glib::ustring> artists{"GNOME Design Team"};
  std::vector<glib::ustring> documenters{"Angela Avery"};
  std::vector<glib::ustring> credits{"Angela Avery"};
  std::vector<glib::ustring> acknowledgements{"Angela Avery"};

  window->set_application_name ("Example");
  window->set_application_icon ("org.gnome.Example");
  window->set_developer_name ("Angela Avery");
  window->set_version ("1.2.3");
  window->set_release_notes_version ("1.2.0");
  window->set_release_notes ("<p>Example</p>");
  window->set_comments ("Comments");
  window->set_website ("https://example.org");
  window->set_issue_url ("https://example.org");
  window->set_support_url ("https://example.org");
  window->set_debug_info ("Debug");
  window->set_debug_info_filename ("debug.txt");
  window->set_developers (developers);
  window->set_designers (designers);
  window->set_artists (artists);
  window->set_documenters (documenters);
  window->set_translator_credits ("translator-credits");
  // window->set_copyright("© 2022 Angela Avery"); // © is two bytes. ustring
  // isn't wide.
  window->set_license_type (gtk::License::GPL_3_0);

  g_assert_true (window->get_application_name () == "Example");
  g_assert_true (window->get_application_icon () == "org.gnome.Example");
  g_assert_true (window->get_developer_name () == "Angela Avery");
  g_assert_true (window->get_version () == "1.2.3");
  g_assert_true (window->get_release_notes_version () == "1.2.0");
  g_assert_true (window->get_release_notes () == "<p>Example</p>");
  g_assert_true (window->get_comments () == "Comments");
  g_assert_true (window->get_website () == "https://example.org");
  g_assert_true (window->get_issue_url () == "https://example.org");
  g_assert_true (window->get_support_url () == "https://example.org");
  g_assert_true (window->get_debug_info () == "Debug");
  g_assert_true (window->get_debug_info_filename () == "debug.txt");
  g_assert_true (window->get_developers () == developers);
  g_assert_true (window->get_designers () == designers);
  g_assert_true (window->get_artists () == artists);
  g_assert_true (window->get_documenters () == documenters);
  g_assert_true (window->get_translator_credits () == "translator-credits");
  // g_assert_true(window->get_copyright() == "© 2022 Angela Avery"); // © is
  // two bytes. ustring isn't wide.
  g_assert_true (window->get_license_type () == gtk::License::GPL_3_0);

  window->add_link ("Example", "https://example.org");
  window->add_credit_section ("Example", credits);
  window->add_acknowledgement_section ("Example", acknowledgements);
  window->add_legal_section ("Example",
                             "© 2022 Example",
                             gtk::License::GPL_3_0,
                             "");
  window->add_legal_section ("Example",
                             "© 2022 Example",
                             gtk::License::GPL_3_0,
                             "License");

  delete window;
}

int
main (int argc, char* argv[])
{
  gtk_test_init (&argc, &argv, NULL);
  adw::init ();

  g_test_add_func ("/Adwaita/AboutWindow/create", test_adw_about_window_create);

  return g_test_run ();
}
