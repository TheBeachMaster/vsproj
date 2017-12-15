using System;

using TempStudio.ViewModels;

using Windows.UI.Xaml.Controls;

namespace TempStudio.Views
{
    public sealed partial class MainPage : Page
    {
        private MainViewModel ViewModel
        {
            get { return DataContext as MainViewModel; }
        }

        public MainPage()
        {
            InitializeComponent();
        }
    }
}
