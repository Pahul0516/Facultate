
using System.ComponentModel.DataAnnotations;
using Validator = Lab10.Domain.Validator;

namespace Lab10.UI;

public class UI
{
    private Controller.Controller c = new Controller.Controller();
    private List<String> options = new List<String> {
        "1. Toti jucatorii unei echipe", 
        "2. Toti jucatorii activi ai unei echipe la un anumit meci",
        "3. Sa se afiseze toate meciurile dintr-o anumita perioada calendaristica",
        "4. Sa se determine si sa se afiseze scorul de la un anumit meci"
    };

    public UI()
    {
        c.load_from_db();
    }

    public void show_options() {
        Console.WriteLine(String.Join("\n", options.Select(s => s)));
        Console.WriteLine("Te rog sa intoroduci o optiune");
    }
    
    public void run() {
        while (true)
        {
            show_options();
            int o = int.Parse(Console.ReadLine()); 
            int id = 1;
            switch (o)
            {
                case 1:
                    Console.WriteLine("Te rog sa introduci un id de echipa");
                    id = int.Parse(Console.ReadLine());
                    Console.WriteLine(string.Join("\n",c.raport1(id).Select(j => j.ToString())));
                    break;
                case 2:
                    Console.WriteLine("Te rog sa introduci un id de meci");
                    id = int.Parse(Console.ReadLine());
                    var pair = c.raport2(id);
                    var teams = pair.Item1.Concat(pair.Item2).Select(j => j.Echipa.Name).Distinct().ToList();
                    Console.ForegroundColor = ConsoleColor.Cyan;
                    Console.Write(teams[0]);
                    Console.ForegroundColor = ConsoleColor.White;
                    Console.Write(" VS ");
                    Console.ForegroundColor = ConsoleColor.Red;
                    Console.Write(teams[1] + "\n");
                    Console.ForegroundColor = ConsoleColor.Cyan;
                    Console.WriteLine(teams[0] + ":");
                    Console.WriteLine(string.Join("\n",pair.Item1.Select(j=>j.ToString())));
                    Console.ForegroundColor = ConsoleColor.Red;
                    Console.WriteLine(teams[1] + ":");
                    Console.WriteLine(string.Join("\n",pair.Item2.Select(j=>j.ToString())));
                    Console.ForegroundColor = ConsoleColor.White;
                    break;
                case 3:
                    Console.WriteLine("Te rog sa introduci anul luna si ziua celor 2 date");
                    int an1, luna1, zi1, an2, luna2, zi2;
                    Validator v = new Validator();
                    try
                    {
                        
                        an1 = int.Parse(Console.ReadLine());
                        luna1 = int.Parse(Console.ReadLine());
                        zi1 = int.Parse(Console.ReadLine());
                        v.Validate(an1,luna1,zi1);
                        an2 = int.Parse(Console.ReadLine());
                        luna2 = int.Parse(Console.ReadLine());
                        zi2 = int.Parse(Console.ReadLine());
                        v.Validate(an2,luna2,zi2);
                        var results = c.raport3(new DateTime(an1, luna1, zi1), new DateTime(an2, luna2, zi2));
                        foreach (var match in results)
                        {
                            Console.WriteLine(match.FirstTeamName + " VS " + match.SecondTeamName);
                        }
                    }
                    catch (Exception e)
                    {
                        Console.WriteLine(e.Message);
                    }
                    break;
                case 4:
                    Console.WriteLine("Te rog sa introduci id-ul meciului");
                    id = int.Parse(Console.ReadLine());
                    var pair2= c.raport4(id);
                    Console.ForegroundColor = ConsoleColor.Cyan;
                    Console.Write(pair2.Item1.TeamName);
                    Console.ForegroundColor = ConsoleColor.White;
                    Console.Write(" VS ");
                    Console.ForegroundColor = ConsoleColor.Red;
                    Console.Write(pair2.Item2.TeamName + "\n");
                    Console.ForegroundColor = ConsoleColor.White;
                    Console.WriteLine(pair2.Item1.Score + "  " + pair2.Item2.Score);
                    break;
                default:
                    break;
            }
        }
    }
}