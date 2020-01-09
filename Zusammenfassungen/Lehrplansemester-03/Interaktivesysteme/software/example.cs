public partial class MainWindow : INotifyPropertyChanged
{
	public event PropertyChangedEventHandler PropertyChanged;

	private void NotifyPropertyChanged([CallerMemberName] String name = "")
	{
		PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(name));
	}

	public MainWindow()
	{
		InitializeComponent();
		Binding binding = new Binding("Storage")
		{
			Source = this,
			UpdateSourceTrigger = UpdateSourceTrigger.PropertyChanged,
			Mode = BindingMode.TwoWay
		};
		Box2.SetBinding(TextBox.TextProperty, binding);
	}

	private string _storage;
	public string Storage
	{
		get
		{
			return this._storage;
		}
  
		set
		{
			if (value != this._storage)
			{
				this._storage = value;
				NotifyPropertyChanged();
			}
		}
	}
}