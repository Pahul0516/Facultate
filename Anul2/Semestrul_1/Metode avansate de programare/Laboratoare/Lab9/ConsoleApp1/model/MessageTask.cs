namespace ConsoleApp1.model;

public class MessageTask : Task
{
    private string Message {get; set; }
    private string From { get; set; }
    private string To{ get; set; }
    private DateTime Date{ get; set; }
    
    public MessageTask(string id, string description, string message, string from, string to, DateTime date) 
        : base(id, description)
    {
        this.Message = message;
        this.From = from;
        this.To = to;
        this.Date = date;
    }

    public override void Execute()
    {
        System.Console.WriteLine(Date.ToShortDateString() + " : " + Message);
    }

    public override string ToString()
    {
        return
            $"{base.ToString()}, {nameof(Message)}: {Message}, {nameof(From)}: {From}, {nameof(To)}: {To}, {nameof(Date)}: {Date}";
    }
}