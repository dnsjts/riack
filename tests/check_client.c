#include <riack/riack.h>

START_TEST (test_riack_client_new_and_free)
{
  riack_client_t *client;

  client = riack_client_new ();
  ck_assert (client != NULL);

  ck_assert_errno (riack_client_free (NULL), EINVAL);
  ck_assert_errno (riack_client_free (client), ENOTCONN);
}
END_TEST

START_TEST (test_riack_client_connect_and_disconnect)
{
  riack_client_t *client;

  ck_assert_errno (riack_client_disconnect (NULL), ENOTCONN);

  client = riack_client_new ();

  ck_assert_errno (riack_client_disconnect (client), ENOTCONN);

  if (network_tests_enabled ())
    {
      /* Connect with default options! */
      ck_assert_errno (riack_client_connect (client, RIACK_CONNECT_OPTION_NONE),
                       0);
      ck_assert_errno (riack_client_disconnect (client), 0);

      /* Connect to "localhost", instead of "127.0.0.1" */
      ck_assert_errno (riack_client_connect
                       (client,
                        RIACK_CONNECT_OPTION_HOST, "localhost",
                        RIACK_CONNECT_OPTION_NONE), 0);
      riack_client_disconnect (client);

      /* Connect to 8087, explicitly. */
      ck_assert_errno (riack_client_connect
                       (client,
                        RIACK_CONNECT_OPTION_PORT, 8087,
                        RIACK_CONNECT_OPTION_NONE), 0);
      riack_client_disconnect (client);
    }

  riack_client_free (client);
}
END_TEST

static TCase *
test_riack_client (void)
{
  TCase *test_client;

  test_client = tcase_create ("Client");
  tcase_add_test (test_client, test_riack_client_new_and_free);
  tcase_add_test (test_client, test_riack_client_connect_and_disconnect);

  return test_client;
}
