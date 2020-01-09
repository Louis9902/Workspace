class DataStorage : INotifyPropertyChanged
{
	public event PropertyChangedEventHandler PropertyChanged;

	private void NotifyPropertyChanged([CallerMemberName] String name = "")
	{
		PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(name));
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