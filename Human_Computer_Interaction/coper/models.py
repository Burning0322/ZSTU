from django.db import models


# Create your models here.
class ReactorModel(models.Model):
    title = models.CharField(max_length=255)
    description = models.TextField(blank=True, null=True)

    class Meta:
        verbose_name = u'堆型号'
        verbose_name_plural = u'01.堆型号'

    def __str__(self):
        return self.title


class Task(models.Model):
    title = models.CharField(max_length=255)
    description = models.TextField(blank=True, null=True)

    class Meta:
        verbose_name = u'任务'
        verbose_name_plural = u'02.任务列表'

    def __str__(self):
        return self.title


class TrunkType(models.Model):
    title = models.CharField(max_length=255)
    description = models.TextField(blank=True, null=True)

    class Meta:
        verbose_name = u'知识类别'
        verbose_name_plural = u'03.知识类别'

    def __str__(self):
        return self.title


class DKnowledge(models.Model):
    title = models.CharField(max_length=255)
    description = models.TextField(blank=True, null=True)
    reactormodel = models.ForeignKey(ReactorModel, on_delete=models.CASCADE, related_name='reactormodel')
    task = models.ForeignKey(Task, on_delete=models.CASCADE, related_name='task')
    trunktype = models.ForeignKey(TrunkType, on_delete=models.CASCADE, related_name='trunktype')

    class Meta:
        verbose_name = u'陈述知识'
        verbose_name_plural = u'04.陈述列表'

    def __str__(self):
        return self.title


class PKnowledge(models.Model):
    condition = models.CharField(max_length=255)
    outcome = models.CharField(max_length=255)

    class Meta:
        verbose_name = u'过程知识'
        verbose_name_plural = u'05.过程知识列表'

    def __str__(self):
        return (str(self.condition) + "\t\t=>\t\t" + str(self.outcome))


class CognitiveModel(models.Model):
    name = models.CharField(max_length=255)
    author = models.CharField(max_length=255)
    taskname = models.CharField(max_length=255)  # models.ForeignKey(Task, on_delete=models.CASCADE)
    description = models.TextField(blank=True, null=True)
    production = models.ManyToManyField('PKnowledge')

    class Meta:
        verbose_name = u'认知模型'
        verbose_name_plural = u'06.认知模型'

    def __str__(self):
        return self.name
