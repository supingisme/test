#include "soapcalcProxy.h"
#include "calc.nsmap"

char server[256] = "http://127.0.0.1:";

int main(int argc, char **argv)
{ if (argc < 5)
  { fprintf(stderr, "Usage: [add|sub|mul|div|pow] num num port\n");
    exit(0);
  }
  double a, b, result;
  a = strtod(argv[2], NULL);
  b = strtod(argv[3], NULL);
  calcProxy calc;
  strcat(server, argv[4]);
  calc.soap_endpoint = server;
  switch (*argv[1])
  { case 'a':
      calc.add(a, b, &result);
      break;
    case 's':
      calc.sub(a, b, &result);
      break;
    case 'm':
      calc.mul(a, b, &result);
      break;
    case 'd':
      calc.div(a, b, &result);
      break;
    case 'p':
      calc.pow(a, b, &result);
      break;
    default:
      fprintf(stderr, "Unknown command\n");
      exit(0);
  }
  if (calc.error)
    calc.soap_stream_fault(std::cerr);
  else
    printf("result = %g\n", result);
  return 0;
}

