using System;
using Android.App;
using Android.Content;
using Android.OS;
using Android.Widget;

namespace GroceryList
{
	[Activity(Label = "About")]			
	public class AboutActivity : Activity
	{
		protected override void OnCreate(Bundle bundle)
		{
			base.OnCreate(bundle);
			SetContentView(Resource.Layout.About);

			FindViewById<Button>(Resource.Id.learnMoreButton).Click += OnLearnMoreClick;
            FindViewById<Button>(Resource.Id.CallMe).Click += OnCallMeClick;
            FindViewById<Button>(Resource.Id.MailMe).Click += OnMailMeClick;
            FindViewById<Button>(Resource.Id.ShowMap).Click += OnShowMapClick;
            FindViewById<Button>(Resource.Id.SetAlarm).Click += OnSetAlarmClick;
            FindViewById<Button>(Resource.Id.SetEvent).Click += OnSetEventClick;
            FindViewById<Button>(Resource.Id.SetNotify).Click += OnSetNotifyClick;
        }

		void OnLearnMoreClick(object sender, EventArgs e)
		{
			var intent = new Intent();

			//
			// Use ActionView with an http Data value to launch Android's web browser Activity.
			//
			intent.SetAction(Intent.ActionView);
			intent.SetData(Android.Net.Uri.Parse("http://www.xamarin.com"));

			StartActivity(intent);
		}

        void OnShowMapClick(object sender, EventArgs e)
		{
			var intent = new Intent();

			intent.SetAction(Intent.ActionView);
			intent.SetData(Android.Net.Uri.Parse("geo:37.797776,-122.401881?z=16"));

			StartActivity(intent);
		}
        void OnCallMeClick(object sender, EventArgs e)
        {
            var intent = new Intent();

            intent.SetAction(Intent.ActionDial);
            intent.SetData(Android.Net.Uri.Parse("tel:0723256388"));

            StartActivity(intent);
        }
        void OnMailMeClick(object sender, EventArgs e)
        {
            var intent = new Intent();

            intent.SetAction(Intent.ActionSend);
            intent.SetData(Android.Net.Uri.Parse("mailto:"));
            intent.PutExtra(Intent.ExtraEmail, new string[] {"criale@yahoo.com"});
            intent.PutExtra(Intent.ExtraSubject, "How are you" );
            //if (intent.ResolveActivity(PackageManager) != null)
            {
                StartActivity(intent);
            }
        }
        void OnSetNotifyClick(object sender, EventArgs e)
        {
            var intent = new Intent();

            intent.SetAction(Intent.ActionView);
            intent.SetData(Android.Net.Uri.Parse("geo:37.797776,-122.401881?z=16"));

            StartActivity(intent);
        }
        void OnSetEventClick(object sender, EventArgs e)
        {
            var intent = new Intent();

            intent.SetAction(Intent.ActionView);
            intent.SetData(Android.Net.Uri.Parse("geo:37.797776,-122.401881?z=16"));
            //intent.SetAction(Android.Provider.CalendarContract.ActionEventReminder);
            //intent.PutExtra(Android.Provider.CalendarContract.ExtraEventAllDay, 1);

            StartActivity(intent);
        }
        void OnSetAlarmClick(object sender, EventArgs e)
        {
            var intent = new Intent();
                
            intent.SetAction(Android.Provider.AlarmClock.ActionSetAlarm);
            intent.PutExtra(Android.Provider.AlarmClock.ExtraMessage, "New Alarm");
            intent.PutExtra(Android.Provider.AlarmClock.ExtraHour, 9);
            intent.PutExtra(Android.Provider.AlarmClock.ExtraMinutes, 30);

            StartActivity(intent);
        }
    }
}