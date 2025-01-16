using Lab10;
using Lab10.Controller;
using Lab10.Domain;
using Lab10.UI;

Controller c = new Controller();

c.load_from_db();

//Console.WriteLine(string.Join("\n",c.raport1(2).Select(j => j.ToString())));

// var pair = c.raport2(1);
// var teams = pair.Item1.Concat(pair.Item2).Select(j => j.Echipa.Name).Distinct().ToList();
// Console.ForegroundColor = ConsoleColor.Cyan;
// Console.Write(teams[0]);
// Console.ForegroundColor = ConsoleColor.White;
// Console.Write(" VS ");
// Console.ForegroundColor = ConsoleColor.Red;
// Console.Write(teams[1] + "\n");
// Console.ForegroundColor = ConsoleColor.Cyan;
// Console.WriteLine(teams[0] + ":");
// Console.WriteLine(string.Join("\n",pair.Item1.Select(j=>j.ToString())));
// Console.ForegroundColor = ConsoleColor.Red;
// Console.WriteLine(teams[1] + ":");
// Console.WriteLine(string.Join("\n",pair.Item2.Select(j=>j.ToString())));

// var results = c.raport3(new DateTime(2024, 1, 1), new DateTime(2024, 1, 2));
// foreach (var match in results)
// {
//     Console.WriteLine(match.FirstTeamName + " VS " + match.SecondTeamName);
// }



UI u = new UI();
u.run();